#pragma once
#include <iostream>
#include "clsBankClients.h"
#include "clsHeader.h"
using namespace std;

class clsFindClientScreen : protected clsHeader
{
public:

	static void FindClient()
	{
		string title = "Find Client Screen";

		clsHeader::HeaderOfScreen(title);

		cout << "Enter an account number to find: ";
		cin.ignore(1, '\n');
		string accNum = clsInputValidate::ReadString();

		clsBankClients Client = clsBankClients::FindClient(accNum);

		if (clsBankClients::IsExist(accNum))
		{
			cout << '\n';
			Client.Print();
		}
		else
			cout << "\nClient was not found.\n";
	}
};
