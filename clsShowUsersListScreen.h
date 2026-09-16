#pragma once
#include <iostream>
#include "clsHeader.h"
#include "clsBankUsers.h"
using namespace std;

class clsShowUsersListScreen : protected clsHeader
{
public:

	static void ShowUsersList()
	{
		vector <clsBankUsers> vUsers = clsBankUsers::LoadUsersFromFileToVector();

		string title = "Show Users List Screen",
			subTitle = '(' + to_string(vUsers.size()) + ") Users";

		clsHeader::HeaderOfScreen(title, subTitle);

		cout << "-----------------------------------------------------------------------------------------------------------\n";
		cout << "  First Name  |   Last Name  |        Email        |    Phone    |  Username  |  Password  |  Permissions\n";
		cout << "-----------------------------------------------------------------------------------------------------------\n";

		for (int i = 0; i < vUsers.size(); i++)
		{
			cout << setw(11) << vUsers[i].FirstName << "   |";
			cout << setw(12) << vUsers[i].LastName << "  |";
			cout << setw(18) << vUsers[i].Email << "   |";
			cout << setw(12) << vUsers[i].Phone << " |";
			cout << setw(11) << vUsers[i].Username << " |";
			cout << setw(8) << vUsers[i].Password << "    |";
			cout << setw(7) << vUsers[i].Permissions << "\n";
		}
	}
};