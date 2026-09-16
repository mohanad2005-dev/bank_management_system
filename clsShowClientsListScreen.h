#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClients.h"
#include "clsHeader.h"
using namespace std;

class clsShowClientsListScreen : protected clsHeader
{
public:

	static void ShowClientsList()
	{
		vector <clsBankClients> vClients = clsBankClients::LoadClientsFromFileToVector();

		string title = "Show Clients List Screen",
			subTitle = '(' + to_string(vClients.size()) + ") Clients";

		clsHeader::HeaderOfScreen(title, subTitle);

		cout << "-----------------------------------------------------------------------------------------------------------------\n";
		cout << "  First Name  |   Last Name  |        Email        |    Phone    |  Account Number  |  Pin Code  |  Balance '$'\n";
		cout << "-----------------------------------------------------------------------------------------------------------------\n";

		for (int i = 0; i < vClients.size(); i++)
		{
			cout << setw(11) << vClients[i].FirstName << "   |";
			cout << setw(12) << vClients[i].LastName << "  |";
			cout << setw(18) << vClients[i].Email << "   |";
			cout << setw(12) << vClients[i].Phone << " |";
			cout << setw(11) << vClients[i].AccountNumber() << "       |";

			cout << setw(8) << vClients[i].PinCode << "    |";
			cout << setw(9) << vClients[i].Balance << "\n";
		}
	}
};