#pragma once
#include <iostream>
#include "clsHeader.h"
#include "clsBankCurrencies.h"
using namespace std;

class clsUpdateCurrencyScreen : protected clsHeader
{
public:

	static void UpdateCurrency()
	{
		clsHeader::HeaderOfScreen("Update Currency Screen");

		string code;
		float newRate;
		char choice;

		cout << "Enter a currency code: ";
		cin >> code;

		clsBankCurrencies Currency = clsBankCurrencies::FindByCode(code);

		if (!Currency.IsEmpty())
		{
			cout << '\n';

			Currency.PrintCurrencyCard();

			cout << "\n\nEnter the new rate: ";
			cin >> newRate;

			cout << "\nAre you sure you want to update this currency rate?[y/n] ";
			cin >> choice;

			if (tolower(choice) == 'y')
			{
				Currency.UpdateRate(newRate);
				cout << "\nUpdate currency rate was successfully.\n";
			}
			else
				cout << "\nCanceled update currency rate.\n";

		}
		else
			cout << "\nCurrency was not found.\n";
	}
};