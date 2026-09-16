#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "clsHeader.h"
#include "clsBankUsers.h"
#include "clsString.h"
using namespace std;

class clsShowLoginRegisterScreen : protected clsHeader
{
public:

	static void ShowLoginRegister()
	{
		vector <clsBankUsers::stRegister> vRegister = clsBankUsers::LoadRegistersFromFileToVector();

		clsHeader::HeaderOfScreen("Login Registers Screen", to_string(vRegister.size()) + " Register");
		
		cout << "      Date - Time      |  Username  |  Password  |  Permissions\n";
		cout << "---------------------------------------------------------------\n";

		for (int i = 0; i < vRegister.size(); i++)
		{
			cout << setw(22) << vRegister[i].dateAndtime << " |";
			cout << setw(10) << vRegister[i].username << "  |";
			cout << setw(9) << vRegister[i].pass << "   |";
			cout << setw(8) << vRegister[i].permissions << '\n';
		}
	}
};