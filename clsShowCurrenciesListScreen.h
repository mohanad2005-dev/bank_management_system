#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "clsHeader.h"
#include "clsBankCurrencies.h"
using namespace std;

class clsShowCurrenciesListScreen : protected clsHeader
{
public:

	static void ShowCurrenciesList()
	{
		vector <clsBankCurrencies> vCurrencies = clsBankCurrencies::LoadCurrenciesDataFromFileToVector();

		string subTitle = '(' + to_string(vCurrencies.size()) + ") Currency";

		clsHeader::HeaderOfScreen("Currencies List Screen", subTitle);

		if (vCurrencies.size() == 0)
			cout << "\nThere are no currencies.\n";
		else
		{
			cout << "          Country           | Currency Code |             Currency Name              |  Rate (1$)";
			cout << "\n--------------------------------------------------------------------------------------------------\n";

			for (int i = 0; i < vCurrencies.size(); i++)
			{
				cout << setw(26) << vCurrencies[i].Country() << "  |";
				cout << setw(9) << vCurrencies[i].CurrencyCode() << "      |";
				cout << setw(39) << vCurrencies[i].CurrencyName() << " |";
				cout << setw(9) << vCurrencies[i].Rate << '\n';
			}

			cout << "--------------------------------------------------------------------------------------------------\n";
		}
	}
};