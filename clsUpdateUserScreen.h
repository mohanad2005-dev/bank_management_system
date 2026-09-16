#pragma once
#include <iostream>
#include "clsHeader.h"
#include "clsBankUsers.h"
using namespace std;

class clsUpdateUserScreen : protected clsHeader
{
public:

	static void UpdateUser()
	{
		clsHeader::HeaderOfScreen("Update User Screen");

		string username;

		cout << "Enter an username to update: ";
		cin >> username;

		while (!clsBankUsers::IsExist(username))
		{
			cout << "\nThis user was not found, please enter another one: ";
			cin >> username;
		}

		clsBankUsers User = clsBankUsers::FindUser(username);

		cout << '\n';
		User.Print();

		clsBankUsers::ReadUserInfo(User);

		clsBankUsers::enSave Save = User.Save();

		switch (Save)
		{
		case clsBankUsers::enSave::Faild_empty:
			cout << "\nError, user was not updated because it's empty.\n";
			break;
		case clsBankUsers::enSave::Successed:
			cout << "\nAccount Updated Successfully.\n";
		}
	}
};