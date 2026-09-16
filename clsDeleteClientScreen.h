#pragma once
#include <iostream>
#include "clsBankClients.h"
#include "clsHeader.h"
using namespace std;

class DeleteClientScreen : protected clsHeader
{
public:

	static void DeleteClient()
	{
		string title = "Delete Client Screen";

		clsHeader::HeaderOfScreen(title);

		string accNum;

		cout << "Enter an account number: ";
		cin >> accNum;

		while (!clsBankClients::IsExist(accNum))
		{
			cout << "\nThis account was not found, please enter another one: ";
			cin >> accNum;
		}

		clsBankClients Client = clsBankClients::FindClient(accNum);

		cout << '\n';

		Client.Print();

		char c;

		cout << "Are you sure you want to delete this account?[y/n] ";
		cin >> c;

		if (tolower(c) == 'y')
		{
			Client.clsBankClients::Delete();
			cout << "\nClient Deleted Successfully.\n";
		}
		else
			cout << "\nCanceled Client Deleted.\n";
	}
};