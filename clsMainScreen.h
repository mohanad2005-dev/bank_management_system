#pragma once
#include <iostream>
#include "clsHeader.h"
#include "clsInputValidate.h"
#include "clsBankUsers.h"
#include "clsShowClientsListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include "clsShowLoginRegisterScreen.h"
#include "clsCurrenciesScreen.h"
using namespace std;

class clsMainScreen : protected clsHeader
{
	enum _enOperation { Show = 1, Add = 2, Delete = 3, Update = 4, Find = 5, Transactions = 6, Manage = 7, Register = 8, Currencies = 9, Logout = 10 };
	enum _enPermissions { pShow = 1, pAdd = 2, pDelete = 4, pUpdate = 8, pFind = 16, pTransactions = 32, pManage = 64, pCurrencies = 128, pRegister = 256 };

	static short _ReadChoice()
	{
		cout << "Choose what do you want to do?[1-10] ";
		int choice = clsInputValidate::ReadNumberBetween<int>("Invalid, please enter a correct value: ", 1, 10);

		return choice;
	}

	static void _GoBackToMainMenue()
	{
		cout << "\nEnter any key to return to 'Main Menue Screen' ...";
		system("pause > 0");
		system("cls");
		ShowMainMenue();
	}

	static void PrintAccessDeniedMessage()
	{
		system("cls");
		cout << "  Access Denied!, contact your admin";
		cout << "\n--------------------------------------\n";
		_GoBackToMainMenue();
	}

	static void _ShowClientsListScreen()
	{
		if (CurrentUser.CheckPermission(_enPermissions::pShow))
			clsShowClientsListScreen::ShowClientsList();
		else
			PrintAccessDeniedMessage();
	}

	static void _AddNewClientScreen()
	{
		if (CurrentUser.CheckPermission(_enPermissions::pAdd))
			clsAddNewClientScreen::AddNewClient();
		else
			PrintAccessDeniedMessage();
	}

	static void _DeleteClientScreen()
	{
		if (CurrentUser.CheckPermission(_enPermissions::pDelete))
			DeleteClientScreen::DeleteClient();
		else
			PrintAccessDeniedMessage();
	}

	static void _UpdateClientInfoScreen()
	{
		if (CurrentUser.CheckPermission(_enPermissions::pUpdate))
			clsUpdateClientScreen::UpdateClient();
		else
			PrintAccessDeniedMessage();
	}

	static void _FindClientScreen()
	{
		if (CurrentUser.CheckPermission(_enPermissions::pFind))
			clsFindClientScreen::FindClient();
		else
			PrintAccessDeniedMessage();
	}

	static void _TransactionsScreen()
	{
		if (CurrentUser.CheckPermission(_enPermissions::pTransactions))
			clsTransactionsScreen::ShowTransactionsScreen();
		else
			PrintAccessDeniedMessage();
	}

	static void _ManageUsersScreen()
	{
		if (CurrentUser.CheckPermission(_enPermissions::pManage))
			clsManageUsersScreen::ShowManageUsersScreen();
		else
			PrintAccessDeniedMessage();
	}

	static void _ShowRegisterScreen()
	{
		if (CurrentUser.CheckPermission(_enPermissions::pRegister))
			clsShowLoginRegisterScreen::ShowLoginRegister();
		else
			PrintAccessDeniedMessage();
	}

	static void _ShowCurrenciesScreen()
	{
		if (CurrentUser.CheckPermission(_enPermissions::pCurrencies))
			clsShowCurrenciesScreen::ShowCurrenciesScreen();
		else
			PrintAccessDeniedMessage();
	}

	static void _PerformMainSystem(_enOperation operation)
	{
		switch (operation)
		{

		case _enOperation::Show:
			system("cls");
			_ShowClientsListScreen();
			_GoBackToMainMenue();
			break;

		case _enOperation::Add:
			system("cls");
			_AddNewClientScreen();
			_GoBackToMainMenue();
			break;

		case _enOperation::Delete:
			system("cls");
			_DeleteClientScreen();
			_GoBackToMainMenue();
			break;

		case _enOperation::Update:
			system("cls");
			_UpdateClientInfoScreen();
			_GoBackToMainMenue();
			break;

		case _enOperation::Find:
			system("cls");
			_FindClientScreen();
			_GoBackToMainMenue();
			break;

		case _enOperation::Transactions:
			system("cls");
			_TransactionsScreen();
			ShowMainMenue();
			break;

		case _enOperation::Manage:
			system("cls");
			_ManageUsersScreen();
			ShowMainMenue();
			break;

		case _enOperation::Register:
			system("cls");
			_ShowRegisterScreen();
			_GoBackToMainMenue();
			break;

		case _enOperation::Currencies:
			system("cls");
			_ShowCurrenciesScreen();
			_GoBackToMainMenue();
			break;
			
		case _enOperation::Logout:
			CurrentUser = clsBankUsers::FindUser("", "");

		}
	}

public:

	static void ShowMainMenue()
	{
		clsHeader::HeaderOfScreen("Main Screen");

		cout << "------------------------------------------\n";
		cout << "               Main Menue\n";
		cout << "------------------------------------------";
		cout << "\n          [1] Show Clients List";
		cout << "\n          [2] Add New Client";
		cout << "\n          [3] Delete Client";
		cout << "\n          [4] Update Client Info";
		cout << "\n          [5] Find Client";
		cout << "\n          [6] Transactions";
		cout << "\n          [7] Manage Users";
		cout << "\n          [8] Login Registers";
		cout << "\n          [9] Currencies Exchange";
		cout << "\n          [10] Logout";
		cout << "\n----------------------------------------\n";

		_PerformMainSystem(_enOperation(_ReadChoice()));
	}
};