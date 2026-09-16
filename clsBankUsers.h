#pragma once
#include <iostream>
#include "clsPerson.h"
#include <vector>
#include <fstream>
#include <string>
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsBankClients.h"
#include "clsUtil.h"
#include "Global.h"
using namespace std;

const string UsersFile = "UsersFile.txt";

class clsBankUsers : public clsPerson
{
	string _Username, _Password;
	int _Permissions = 0;

	enum enMode { Empty = 0, Update = 1, AddNew = 2 };
	enMode _Mode;

	static clsBankUsers _ConvertLineToUserObject(string line)
	{
		vector <string> vClient = clsString::Split(line, Seperator);

		return clsBankUsers(enMode::Update, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4], clsUtil::DecryptText(vClient[5], 3), stoi(vClient[6]));
	}

	string _ConvertObjectToLine(clsBankUsers object)
	{
		string pass = object.Password;
		pass = clsUtil::EncryptText(pass, 3);

		return object.FirstName + Seperator + object.LastName + Seperator + object.Email + Seperator + object.Phone + Seperator
			+ object.Username + Seperator + pass + Seperator + to_string(object.Permissions);
	}

	static clsBankUsers _GetEmptyUserObject()
	{
		return clsBankUsers(enMode::Empty, "", "", "", "", "", "", 0);
	}

	void _AddNewUser()
	{
		fstream file;
		file.open(UsersFile, ios::app);

		if (file.is_open())
		{
			file << '\n' << _ConvertObjectToLine(*this);

			file.close();
		}
	}

	void _UpdateUser()
	{
		vector <clsBankUsers> vUsers;

		fstream file;
		file.open(UsersFile, ios::in);

		if (file.is_open())
		{
			string line;

			while (getline(file, line))
			{
				clsBankUsers user = _ConvertLineToUserObject(line);

				if (user.Username == Username)
				{
					user = *this;
				}

				vUsers.push_back(user);
			}

			_SaveInFile(vUsers);

			file.close();
		}
	}

	void _SaveInFile(vector <clsBankUsers> vUsers)
	{
		fstream file;
		file.open(UsersFile, ios::out);

		if (file.is_open())
		{
			for (clsBankUsers C : vUsers)
			{
				file << _ConvertObjectToLine(C) << endl;
			}

			file.close();
		}
	}

public:

	clsBankUsers(enMode mode, string firstname, string lastname, string email, string phone, string username, string pass, int permissions)
		: clsPerson(firstname, lastname, email, phone)
	{
		_Mode = mode;
		_Username = username;
		_Password = pass;
		_Permissions = permissions;
	}

	void setUsername(string username)
	{
		_Username = username;
	}

	string getUsername()
	{
		return _Username;
	}

	__declspec(property(get = getUsername, put = setUsername)) string Username;

	void setPassword(string pass)
	{
		_Password = pass;
	}

	string getPassword()
	{
		return _Password;
	}

	__declspec(property(get = getPassword, put = setPassword)) string Password;

	void setPermissions(int persmissions)
	{
		_Permissions = persmissions;
	}

	int getPermissions()
	{
		return _Permissions;
	}

	__declspec(property(get = getPermissions, put = setPermissions)) int Permissions;

	string FullName()
	{
		return FirstName + " " + LastName;
	}

	void Print()
	{
		cout << "            User Info\n";
		cout << "-----------------------------------";
		cout << "\nFirst Name : " << FirstName;
		cout << "\nLast Name  : " << LastName;
		cout << "\nFull Name  : " << FullName();
		cout << "\nEmail      : " << Email;
		cout << "\nPhone      : " << Phone;
		cout << "\nUsername   : " << _Username;
		cout << "\nPassword   : " << _Password;
		cout << "\nPermissions: " << _Permissions;
		cout << "\n-----------------------------------\n";
	}

	static vector <clsBankUsers> LoadUsersFromFileToVector()
	{
		vector <clsBankUsers> vUsers;

		fstream file;
		file.open(UsersFile, ios::in);

		if (file.is_open())
		{
			string line;

			while (getline(file, line))
			{
				vUsers.push_back(_ConvertLineToUserObject(line));
			}

			file.close();
		}

		return vUsers;
	}

	static clsBankUsers FindUser(string username)
	{
		vector <clsBankUsers> vUsers = LoadUsersFromFileToVector();

		for (clsBankUsers client : vUsers)
		{
			if (client._Username == username)
			{
				return client;
			}
		}

		return _GetEmptyUserObject();
	}

	static clsBankUsers FindUser(string username, string pass)
	{
		vector <clsBankUsers> vUsers = LoadUsersFromFileToVector();

		for (clsBankUsers client : vUsers)
		{
			if (client._Username == username && client._Password == pass)
			{
				return client;
			}
		}

		return _GetEmptyUserObject();
	}

	bool IsEmpty()
	{
		return (this->_Mode == enMode::Empty);
	}

	static bool IsExist(string username)
	{
		clsBankUsers user = FindUser(username);

		return (user._Mode != enMode::Empty);
	}

	static clsBankUsers GetAddNewObject(string username)
	{
		return clsBankUsers(enMode::AddNew, "", "", "", "", username, "", 0);
	}

	enum enSave { Faild_empty = 0, Faild_exist = 1, Successed = 2 };

	enSave Save()
	{
		switch (_Mode)
		{
		case enMode::Empty:
			return enSave::Faild_empty;

		case enMode::Update:
			_UpdateUser();
			return enSave::Successed;

		case enMode::AddNew:
			if (IsExist(_Username))
				return enSave::Faild_exist;
			else
			{
				_AddNewUser();
				return enSave::Successed;
			}
		}
	}

	static void ReadUserInfo(clsBankUsers& user)
	{
		cout << "\n            User Info\n";
		cout << "----------------------------------";

		cout << "\nFirst Name    : ";
		cin.ignore(1, '\n');
		user.FirstName = clsInputValidate::ReadString();

		cout << "Last Name     : ";
		user.LastName = clsInputValidate::ReadString();

		cout << "Email         : ";
		user.Email = clsInputValidate::ReadString();

		cout << "Phone         : ";
		user.Phone = clsInputValidate::ReadString();

		cout << "Username      : " << user.Username;

		cout << "\nPassword      : ";
		user.Password = clsInputValidate::ReadString();

		cout << "Permissions   : ";
		user.Permissions = clsInputValidate::ReadNumber<float>("\nInvalid!, please enter a correct value: ");
	}

	void Delete()
	{
		vector <clsBankUsers> vUsers;

		fstream file;
		file.open(UsersFile, ios::in);

		if (file.is_open())
		{
			string line;

			while (getline(file, line))
			{
				clsBankUsers user = _ConvertLineToUserObject(line);

				if (user.Username != Username)
				{
					vUsers.push_back(user);
				}
			}

			*this = _GetEmptyUserObject();
			_SaveInFile(vUsers);

			file.close();
		}
	}

	bool CheckPermission(short Permissions)
	{
		if (this->Permissions == -1)
			return true;
		else if ((Permissions & this->Permissions) == Permissions)
			return true;
		else
			return false;
	}

	struct stRegister
	{
		string dateAndtime, username, pass;
		int permissions;
	};

	static stRegister ConvertLineToRegisterObject(string line)
	{
		vector <string> vRegisters = clsString::Split(line, "#//#");

		stRegister reg;

		reg.dateAndtime = vRegisters[0];
		reg.username = vRegisters[1];
		reg.pass = clsUtil::DecryptText(vRegisters[2], 3);
		reg.permissions = stoi(vRegisters[3]);

		return reg;
	}

	static vector <stRegister> LoadRegistersFromFileToVector()
	{
		vector <stRegister> vRegisters;

		fstream file;
		file.open("LoginRegisterFile.txt", ios::in);

		if (file.is_open())
		{
			string line;

			while (getline(file, line))
			{
				vRegisters.push_back(ConvertLineToRegisterObject(line));
			}

			file.close();
		}

		return vRegisters;
	}
};