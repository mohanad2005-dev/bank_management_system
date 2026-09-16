#pragma once
#include <iostream>
#include "clsBankClients.h"
#include "clsHeader.h"
using namespace std;

class clsUpdateClientScreen : protected clsHeader
{
public:

	static void UpdateClient()
	{
		string title = "Update Client Screen";

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

		clsBankClients::ReadClientInfo(Client);

		clsBankClients::enSave Save = Client.Save();

		switch (Save)
		{
		case clsBankClients::enSave::Faild_empty:
			cout << "\nError, account was not updated because it's empty.\n";
			break;
		case clsBankClients::enSave::Successed:
			cout << "\nAccount Updated Successfully.\n";
		}
	}
};