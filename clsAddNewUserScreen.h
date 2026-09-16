#pragma once
#include <iostream>
#include "clsHeader.h"
#include "clsBankUsers.h"
using namespace std;

class clsAddNewUserScreen : protected clsHeader
{
public:

	static void AddNewUser()
	{
		string title = "Add New User Screen";

		clsHeader::HeaderOfScreen(title);

		string username;

		cout << "Enter an username: ";
		cin >> username;

		while (clsBankUsers::IsExist(username))
		{
			cout << "\nThis user already exist, please enter another one: ";
			cin >> username;
		}

		clsBankUsers User = clsBankUsers::GetAddNewObject(username);

		clsBankUsers::ReadUserInfo(User);

		clsBankUsers::enSave Save = User.Save();

		switch (Save)
		{
		case clsBankUsers::enSave::Faild_empty:
			cout << "\nError, user was not added because it's empty.\n";
			break;

		case clsBankUsers::enSave::Faild_exist:
			cout << "\nError, user was not added because it's already exist.\n";
			break;

		case clsBankUsers::enSave::Successed:
			cout << "\nAdded User Successfully.\n";
		}
	}
};