#pragma once
#include <iostream>
#include <string>
#include "clsHeader.h"
#include "Global.h"
#include "clsMainScreen.h"
#include "clsLoginRegister.h"
using namespace std;

class clsLoginScreen : protected clsHeader
{
public:

	static bool ShowLoginScreen()
	{
		system("cls");

		clsHeader::HeaderOfScreen("Login Screen");

		string username, pass;
		bool faild = false;
		short count = 3;

		do
		{
			count--;

			cout << "Enter username: ";
			cin >> username;

			cout << "Enter password: ";
			cin >> pass;

			CurrentUser = clsBankUsers::FindUser(username, pass);

			if (CurrentUser.IsEmpty())
			{
				faild = true;

				cout << "\nInvalid Username/Password!";
				cout << "\nYou have " << count << " Trials To Login.\n\n";
			}
			else
			{
				system("cls");
				clsLoginRegister::SaveInLoginRegisterFile(username, pass, CurrentUser.Permissions);
				clsMainScreen::ShowMainMenue();
				return true;
			}

			if (count == 0)
			{
				cout << "\n You are locked after 3 faild trials.";
				cout << "\n--------------------------------------\n";
			}

		} while (faild && count != 0);

		return false;
	}
};