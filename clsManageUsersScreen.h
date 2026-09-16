#pragma once
#include <iostream>
#include "clsHeader.h"
#include "clsInputValidate.h"
#include "clsShowUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsFindUserScreen.h"
#include "clsUpdateUserScreen.h"

using namespace std;

class clsManageUsersScreen : protected clsHeader
{
	enum _enOperation { ShowList = 1, Add = 2, Delete = 3, Update = 4, Find = 5, mainMenue = 6 };

	static short _ReadChoice()
	{
		cout << "Choose what do you want to do?[1-6] ";
		int choice = clsInputValidate::ReadNumberBetween<int>("Invalid, please enter a correct value: ", 1, 6);

		return choice;
	}

	static void _GoBackToManageMenue()
	{
		cout << "\nEnter any key to return to 'Manage Users Screen' ...";
		system("pause > 0");
		system("cls");
		ShowManageUsersScreen();
	}

	static void _ShowUsersListScreen()
	{
		clsShowUsersListScreen::ShowUsersList();
	}

	static void _ShowAddUserScreen()
	{
		clsAddNewUserScreen::AddNewUser();
	}

	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::DeleteUser();
	}

	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::UpdateUser();
	}

	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::FindUser();
	}

	static void _PerformManageUsersSystem(_enOperation operation)
	{
		switch (operation)
		{

		case _enOperation::ShowList:
			system("cls");
			_ShowUsersListScreen();
			_GoBackToManageMenue();
			break;

		case _enOperation::Add:
			system("cls");
			_ShowAddUserScreen();
			_GoBackToManageMenue();
			break;

		case _enOperation::Delete:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageMenue();
			break;

		case _enOperation::Update:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageMenue();
			break;

		case _enOperation::Find:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageMenue();
			break;

		case _enOperation::mainMenue:
			system("cls");
		}
	}

public:

	static void ShowManageUsersScreen()
	{
		clsHeader::HeaderOfScreen("Manage Users Screen");

		cout << "------------------------------------------\n";
		cout << "            Manage Users Menue\n";
		cout << "------------------------------------------";
		cout << "\n          [1] Show Users List";
		cout << "\n          [2] Add New User";
		cout << "\n          [3] Delete User";
		cout << "\n          [4] Update User";
		cout << "\n          [5] Find User";
		cout << "\n          [6] Main Menue";
		cout << "\n------------------------------------------\n";

		_PerformManageUsersSystem(_enOperation(_ReadChoice()));
	}
};