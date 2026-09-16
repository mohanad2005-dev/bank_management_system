#pragma once
#include <iostream>
#include "clsBankClients.h"
#include "clsHeader.h"
using namespace std;

class clsAddNewClientScreen : protected clsHeader
{
public:

	static void AddNewClient()
	{
		string title = "Add New Client Screen";
		clsHeader::HeaderOfScreen(title);

		string accNum;

		cout << "Enter an account number: ";
		cin >> accNum;

		while (clsBankClients::IsExist(accNum))
		{
			cout << "\nThis account already exist, please enter another one: ";
			cin >> accNum;
		}

		clsBankClients Client = clsBankClients::GetAddNewObject(accNum);

		clsBankClients::ReadClientInfo(Client);

		clsBankClients::enSave Save = Client.Save();

		switch (Save)
		{
		case clsBankClients::enSave::Faild_empty:
			cout << "\nError, account was not added because it's empty.\n";
			break;
		case clsBankClients::enSave::Successed:
			cout << "\nAdded Clients Successfully.\n";
		}
	}
};