#pragma once
#include <iostream>
#include "clsHeader.h"
#include "clsInputValidate.h"
#include "clsBankClients.h"
using namespace std;

class clsDepositScreen : protected clsHeader
{
public:

	static void Deposit()
	{
		clsHeader::HeaderOfScreen("Deposit Screen");

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

		cout << "Enter the amount of deposit: ";
		float amount = clsInputValidate::ReadNumberBetween<float>("!Invalid, please enter a correct value: ", 1, 10000);

		char c;
		cout << "\nAre you sure you want to complete this deposit operation?[y/n] ";
		cin >> c;

		if (tolower(c) == 'y')
		{
			Client.Deposit(amount);
			cout << "\nDeposit operation successfully.\n";
		}
		else
			cout << "\nCanceled deposit operation.\n";
	}
};