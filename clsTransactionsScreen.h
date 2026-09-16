#pragma once
#include <iostream>
#include "clsHeader.h"
#include "clsInputValidate.h"
#include "clsBankClients.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsShowTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsShowTransferRegistersScreen.h"
using namespace std;

class clsTransactionsScreen : protected clsHeader
{
	enum _enOperation { deposit = 1, withdraw = 2, totalBalances = 3, transfer = 4, transferRegisters = 5, mainMenue = 6 };

	static short _ReadChoice()
	{
		cout << "Choose what do you want to do?[1-6] ";
		int choice = clsInputValidate::ReadNumberBetween<int>("Invalid, please enter a correct value: ", 1, 6);

		return choice;
	}

	static void _GoBackToTransactionsMenue()
	{
		cout << "\nEnter any key to return to 'Transactions Screen' ...";
		system("pause > 0");
		system("cls");
		ShowTransactionsScreen();
	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::Deposit();
	}

	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::Withdraw();
	}

	static void _ShowTotalBalancesScreen()
	{
		clsShowTotalBalancesScreen::ShowTotalBalances();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::TransferScreen();
	}

	static void _ShowTransferRegistersScreen()
	{
		clsShowTransferRegistersScreen::ShowTransferRegisters();
	}

	static void _PerformTransactionsSystem(_enOperation operation)
	{
		switch (operation)
		{

		case _enOperation::deposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;

		case _enOperation::withdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenue();
			break;

		case _enOperation::totalBalances:
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenue();
			break;

		case _enOperation::transfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
			break;

		case _enOperation::transferRegisters:
			system("cls");
			_ShowTransferRegistersScreen();
			_GoBackToTransactionsMenue();
			break;

		case _enOperation::mainMenue:
			system("cls");
		}
	}

public:

	static void ShowTransactionsScreen()
	{
		clsHeader::HeaderOfScreen("Transactions Screen");

		cout << "------------------------------------------\n";
		cout << "            Transactions Menue\n";
		cout << "------------------------------------------";
		cout << "\n            [1] Deposit";
		cout << "\n            [2] Withdraw";
		cout << "\n            [3] Total Balances";
		cout << "\n            [4] Transfer";
		cout << "\n            [5] Transfer Registers";
		cout << "\n            [6] Main Menue";
		cout << "\n------------------------------------------\n";

		_PerformTransactionsSystem(_enOperation(_ReadChoice()));
	}
};