#pragma once
#include <iostream>
#include "clsHeader.h"
using namespace std;

class clsCurrenciesCalculatorScreen : protected clsHeader
{
public:

	static void CurrenciesCalculator()
	{
		clsHeader::HeaderOfScreen("Currencies Calculator Screen");

		string code1, code2;
		float amount, firstAmount;

		cout << "Enter the first currency code: ";
		cin >> code1;

		cout << "Enter the second currency code: ";
		cin >> code2;

		clsBankCurrencies Currency1 = clsBankCurrencies::FindByCode(code1);
		clsBankCurrencies Currency2 = clsBankCurrencies::FindByCode(code2);

		if (Currency1.IsEmpty() || Currency2.IsEmpty())
		{
			cout << "\nError, [first/second] currency was not found.\n";
		}
		else
		{
			cout << "\nEnter the amount: ";
			cin >> amount;

			firstAmount = amount;

			amount = amount / Currency1.Rate;
			amount = amount * Currency2.Rate;

			cout << '\n' << firstAmount << ' ' << Currency1.CurrencyCode() << " = " << amount << ' ' << Currency2.CurrencyCode() << '\n';
		}
	}
};