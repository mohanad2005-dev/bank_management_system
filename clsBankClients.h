#pragma once
#include <iostream>
#include "clsPerson.h"
#include <vector>
#include <fstream>
#include <string>
#include "clsString.h"
#include "clsInputValidate.h"
#include <iomanip>

using namespace std;

const string ClientsFile = "ClientsFile.txt";
const string Seperator = "#//#";

class clsBankClients : public clsPerson
{
	string _AccountNumber, _PinCode;
	float _Balance;

	enum enMode { Empty = 0, Update = 1, AddNew = 2 };

	enMode _Mode;

	static clsBankClients _ConvertLineToClientObject(string line)
	{
		vector <string> vClient = clsString::Split(line, Seperator);

		return clsBankClients(enMode::Update, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4], vClient[5], stof(vClient[6]));
	}

	string _ConvertObjectToLine(clsBankClients object)
	{
		return object.FirstName + Seperator + object.LastName + Seperator + object.Email + Seperator + object.Phone + Seperator
			+ object.AccountNumber() + Seperator + object.PinCode + Seperator + to_string(object.Balance);
	}

	void _SaveInFile(vector <clsBankClients> vClients)
	{
		fstream file;
		file.open(ClientsFile, ios::out);

		if (file.is_open())
		{
			for (clsBankClients C : vClients)
			{
				file << _ConvertObjectToLine(C) << endl;
			}

			file.close();
		}
	}

	void _UpdateClient()
	{
		vector <clsBankClients> vClients;

		fstream file;
		file.open(ClientsFile, ios::in);

		if (file.is_open())
		{
			string line;

			while (getline(file, line))
			{
				clsBankClients client = _ConvertLineToClientObject(line);

				if (client._AccountNumber == AccountNumber())
				{
					client = *this;
				}

				vClients.push_back(client);
			}

			_SaveInFile(vClients);

			file.close();
		}
	}

	void _AddNewClient()
	{
		fstream file;
		file.open(ClientsFile, ios::app);

		if (file.is_open())
		{
			file << _ConvertObjectToLine(*this) << endl;

			file.close();
		}
	}

	static clsBankClients _GetEmptyClientObject()
	{
		return clsBankClients(enMode::Empty, "", "", "", "", "", "", 0);
	}

public:

	clsBankClients(enMode mode, string firstname, string lastname, string email, string phone, string accNum, string pinCode, float balance)
		:clsPerson(firstname, lastname, email, phone)
	{
		_Mode = mode;
		_AccountNumber = accNum;
		_PinCode = pinCode;
		_Balance = balance;
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void setPinCode(string pinCode)
	{
		_PinCode = pinCode;
	}

	string getPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = getPinCode, put = setPinCode)) string PinCode;

	void setBalance(float balance)
	{
		_Balance = balance;
	}

	float getBalance()
	{
		return _Balance;
	}

	__declspec(property(get = getBalance, put = setBalance)) float Balance;

	void Print()
	{
		cout << "            Client Info\n";
		cout << "-----------------------------------";
		cout << "\nFirst Name    : " << FirstName;
		cout << "\nLast Name     : " << LastName;
		cout << "\nFull Name     : " << FullName();
		cout << "\nEmail         : " << Email;
		cout << "\nPhone         : " << Phone;
		cout << "\nAccount Number: " << _AccountNumber;
		cout << "\nPin Code      : " << _PinCode;
		cout << "\nBalance       : " << _Balance << '$';
		cout << "\n-----------------------------------\n";
	}

	static clsBankClients FindClient(string accNum)
	{
		vector <clsBankClients> vClients = LoadClientsFromFileToVector();

		for (clsBankClients client : vClients)
		{
			if (client.AccountNumber() == accNum)
			{
				return client;
			}
		}

		return _GetEmptyClientObject();
	}

	static clsBankClients FindClient(string accNum, string pinCode)
	{
		vector <clsBankClients> vClients = LoadClientsFromFileToVector();

		for (clsBankClients client : vClients)
		{
			if (client.AccountNumber() == accNum && client.PinCode == pinCode)
			{
				return client;
			}
		}

		return _GetEmptyClientObject();
	}

	static bool IsExist(string accNum)
	{
		clsBankClients client = FindClient(accNum);

		return (client._Mode != enMode::Empty);
	}

	enum enSave { Faild_empty = 0, Faild_exist = 1, Successed = 2 };

	enSave Save()
	{
		switch (_Mode)
		{
		case enMode::Empty:
			return enSave::Faild_empty;

		case enMode::Update:
			_UpdateClient();
			return enSave::Successed;

		case enMode::AddNew:
			if (IsExist(_AccountNumber))
				return enSave::Faild_exist;
			else
			{
				_AddNewClient();
				return enSave::Successed;
			}
		}
	}

	static clsBankClients GetAddNewObject(string accNum)
	{
		return clsBankClients(enMode::AddNew, "", "", "", "", accNum, "", 0);
	}

	void Delete()
	{
		vector <clsBankClients> vClients;

		fstream file;
		file.open(ClientsFile, ios::in);

		if (file.is_open())
		{
			string line;

			while (getline(file, line))
			{
				clsBankClients client = _ConvertLineToClientObject(line);

				if (client.AccountNumber() != this->AccountNumber())
				{
					vClients.push_back(client);
				}
			}

			*this = _GetEmptyClientObject();
			_SaveInFile(vClients);

			file.close();
		}
	}

	static vector <clsBankClients> LoadClientsFromFileToVector()
	{
		vector <clsBankClients> vClients;

		fstream file;
		file.open(ClientsFile, ios::in);

		if (file.is_open())
		{
			string line;

			while (getline(file, line))
			{
				vClients.push_back(_ConvertLineToClientObject(line));
			}

			file.close();
		}

		return vClients;
	}

	static void ReadClientInfo(clsBankClients& client)
	{
		cout << "\n        Update Client Info\n";
		cout << "----------------------------------";

		cout << "\nFirst Name    : ";
		cin.ignore(1, '\n');
		client.FirstName = clsInputValidate::ReadString();

		cout << "Last Name     : ";
		client.LastName = clsInputValidate::ReadString();

		cout << "Email         : ";
		client.Email = clsInputValidate::ReadString();

		cout << "Phone         : ";
		client.Phone = clsInputValidate::ReadString();

		cout << "Account Number: " << client.AccountNumber();

		cout << "\nPin Code      : ";
		client.PinCode = clsInputValidate::ReadString();

		cout << "Balance       : ";
		client.Balance = clsInputValidate::ReadNumber<float>("\nInvalid!, please enter a correct value: ");
	}

	void Deposit(float amount)
	{
		vector <clsBankClients> vClients = LoadClientsFromFileToVector();

		for (clsBankClients& client : vClients)
		{
			if (client.AccountNumber() == _AccountNumber)
			{
				client._Balance += amount;
			}
		}

		_SaveInFile(vClients);
	}

	void Withdraw(float amount)
	{
		vector <clsBankClients> vClients = LoadClientsFromFileToVector();

		for (clsBankClients& client : vClients)
		{
			if (client.AccountNumber() == _AccountNumber)
			{
				client._Balance -= amount;
			}
		}

		_SaveInFile(vClients);
	}

	void PrintTransferCard()
	{
		cout << "\n            Client Card\n";
		cout << "-----------------------------------";
		cout << "\nFull Name     : " << FullName();
		cout << "\nAccount Number: " << _AccountNumber;
		cout << "\nBalance       : " << _Balance << '$';
		cout << "\n-----------------------------------\n\n";
	}

	struct stRegister
	{
		string dateAndtime, accNum1, accNum2;
		float amount, balance1, balance2;
		string currentUser;
	};

	static stRegister ConvertLineToRegisterObject(string line)
	{
		vector <string> vRegisters = clsString::Split(line, "#//#");

		stRegister reg;

		reg.dateAndtime = vRegisters[0];
		reg.accNum1 = vRegisters[1];
		reg.accNum2 = vRegisters[2];
		reg.amount = stoi(vRegisters[3]);
		reg.balance1 = stoi(vRegisters[4]);
		reg.balance2 = stoi(vRegisters[5]);
		reg.currentUser = vRegisters[6];

		return reg;
	}

	static vector <stRegister> LoadRegistersFromFileToVector()
	{
		vector <stRegister> vRegisters;

		fstream file;
		file.open("TransferRegisterFile.txt", ios::in);

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