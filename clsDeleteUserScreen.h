#pragma once
#include <iostream>
#include "clsHeader.h"
using namespace std;

class clsDeleteUserScreen : protected clsHeader
{
public:

	static void DeleteUser()
	{
		clsHeader::HeaderOfScreen("Delete User Screen");

		string username;

		cout << "Enter an username: ";
		cin >> username;

		while (!clsBankUsers::IsExist(username))
		{
			cout << "\nThis user was not found, please enter another one: ";
			cin >> username;
		}

		clsBankUsers Client = clsBankUsers::FindUser(username);

		cout << '\n';
		Client.Print();

		char c;

		cout << "Are you sure you want to delete this user?[y/n] ";
		cin >> c;

		if (tolower(c) == 'y')
		{
			Client.clsBankUsers::Delete();
			cout << "\nUser deleted successfully.\n";
		}
		else
			cout << "\nCanceled user deleted.\n";
	}
};