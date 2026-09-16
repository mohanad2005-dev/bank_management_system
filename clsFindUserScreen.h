#pragma once
#include <iostream>
#include "clsHeader.h"
#include "clsBankUsers.h"
using namespace std;

class clsFindUserScreen : protected clsHeader
{
public:

	static void FindUser()
	{
		clsHeader::HeaderOfScreen("Find User Screen");

		cout << "Enter an username to find: ";
		cin.ignore(1, '\n');
		string accNum = clsInputValidate::ReadString();

		clsBankUsers User = clsBankUsers::FindUser(accNum);

		if (clsBankUsers::IsExist(accNum))
		{
			cout << '\n';
			User.Print();
		}
		else
			cout << "\nUser was not found.\n";
	}
};