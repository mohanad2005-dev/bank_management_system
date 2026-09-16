#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "clsHeader.h"
#include "clsBankCurrencies.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindCurrencyScreen : protected clsHeader
{
public:

	static void FindCurrency()
	{
		clsHeader::HeaderOfScreen("Find Currency Screen");

		vector <clsBankCurrencies> vCurrecies = clsBankCurrencies::LoadCurrenciesDataFromFileToVector();

		string code, country;
		short choice;

		cout << "Find by [1]Country or [2]Code? ";
		choice = clsInputValidate::ReadNumberBetween<int>("Error, please enter a valid value: ", 1, 2);

		if (choice == 1)
		{
			cout << "Enter a country: ";
			cin.ignore(1, '\n');
			getline(cin, country);

			clsBankCurrencies Currency = clsBankCurrencies::FindByCountry(country);

			if (!Currency.IsEmpty())
			{
				cout << "\nCurrency was Found (-:\n\n";
				Currency.PrintCurrencyCard();
				cout << '\n';
			}
			else
				cout << "\nCurrency was not Found )-:\n";
		}
		else
		{
			cout << "Enter a code: ";
			cin >> code;

			clsBankCurrencies Currency = clsBankCurrencies::FindByCode(code);

			if (!Currency.IsEmpty())
			{
				cout << "\nCurrency was Found (-:\n\n";
				Currency.PrintCurrencyCard();
				cout << '\n';
			}
			else
				cout << "\nCurrency was not Found )-:\n";
		}
	}
};