#pragma once
#include <iostream>
#include "clsHeader.h"
#include "clsBankClients.h"
using namespace std;

class clsShowTotalBalancesScreen : protected clsHeader
{
public:

	static void ShowTotalBalances()
	{
		vector <clsBankClients> vClients = clsBankClients::LoadClientsFromFileToVector();
		float total = 0;

		string subTitle = '(' + to_string(vClients.size()) + ") Clients";

		clsHeader::HeaderOfScreen("Show Total Balances Screen", subTitle);

		if (vClients.size() == 0)
		{
			cout << "There no clients.\n";
		}
		else
		{
			cout << "--------------------------------------------------------\n";
			cout << "  Account Number  |         Name        |  Balance '$'\n";
			cout << "--------------------------------------------------------\n";

			for (int i = 0; i < vClients.size(); i++)
			{
				cout << setw(11) << vClients[i].AccountNumber() << "       |";
				cout << setw(19) << vClients[i].FullName() << "  |";
				cout << setw(9) << vClients[i].Balance << "\n";

				total += vClients[i].Balance;
			}

			cout << "--------------------------------------------------------\n\n";
			cout << "Total Balances = " << total << "$\n";
			cout << "( " << clsString::NumberToString(int(total)) << "dollar )\n";
		}
	}
};