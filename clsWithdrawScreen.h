#pragma once
#include <iostream>
#include "clsHeader.h"
#include "clsInputValidate.h"
#include "clsBankClients.h"
using namespace std;

class clsWithdrawScreen : protected clsHeader
{
public:

	static void Withdraw()
	{
		clsHeader::HeaderOfScreen("Withdraw Screen");

		cout << "Enter an account number: ";
		cin.ignore(1, '\n');
		string accNum = clsInputValidate::ReadString();

		while (!clsBankClients::IsExist(accNum))
		{
			cout << "Clients with [" << accNum << "] was not found, please enter another account number: ";
			accNum = clsInputValidate::ReadString();
		}

		clsBankClients Client = clsBankClients::FindClient(accNum);

		cout << '\n';
		Client.Print();

		cout << "Enter the amount of withdraw: ";
		float amount = clsInputValidate::ReadNumberBetween<float>("!Invalid, please enter a correct value: ", 1, 10000);

		char c;
		cout << "\nAre you sure you want to complete this withdraw operation?[y/n] ";
		cin >> c;

		if (tolower(c) == 'y')
		{
			Client.Withdraw(amount);
			cout << "\nWithdraw operation successfully.\n";
		}
		else
			cout << "\nCanceled withdraw operation.\n";
	}
};