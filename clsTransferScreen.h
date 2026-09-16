#pragma once
#include <iostream>
#include "clsHeader.h"
#include "clsBankClients.h"
#include "clsTransferRegisters.h"
#include "Global.h"
using namespace std;

class clsTransferScreen : protected clsHeader
{
public:

	static void TransferScreen()
	{
		clsHeader::HeaderOfScreen("Transfer Screen");

		string accFrom, accTo;

		cout << "Enter an account number to transfer from: ";
		cin >> accFrom;

		while (!clsBankClients::IsExist(accFrom))
		{
			cout << "Invalid acc.num, please enter another one: ";
			cin >> accFrom;
		} 

		clsBankClients Client1 = clsBankClients::FindClient(accFrom);
		Client1.PrintTransferCard();

		cout << "Enter an account number to transfer to: ";
		cin >> accTo;

		while (!clsBankClients::IsExist(accTo) || accTo == accFrom)
		{
			cout << "Invalid acc.num, please enter another one: ";
			cin >> accTo;
		}

		clsBankClients Client2 = clsBankClients::FindClient(accTo);
		Client2.PrintTransferCard();


		float amount = 0;
		cout << "\nEnter the amount of transfer: ";
		cin >> amount;

		while (amount > Client1.Balance || amount < 0)
		{
			cout << "\nAmount exceeds the available balance, please enter another amount: ";
			cin >> amount;
		}

		char c;
		cout << "\nAre you sure you want to perform this operation?[y/n] ";
		cin >> c;

		if (tolower(c) == 'y')
		{
			Client1.Withdraw(amount);
			Client2.Deposit(amount);

			clsTransferRegister::SaveInTransferRegisterFile(accFrom, accTo, amount, Client1.Balance - amount, Client2.Balance + amount, CurrentUser.Username);

			cout << "\n Transfer operation successfully.";
			cout << "\n----------------------------------\n";
		}
		else
		{
			cout << "\n Canceled transfer operation.";
			cout << "\n------------------------------\n";
		}
	}
};