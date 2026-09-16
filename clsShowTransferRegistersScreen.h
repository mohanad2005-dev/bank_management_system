#pragma once
#include <iostream>
#include <vector>
#include "clsHeader.h"
#include "clsBankClients.h"
using namespace std;

class clsShowTransferRegistersScreen : protected clsHeader
{
public:

	static void ShowTransferRegisters()
	{
		vector <clsBankClients::stRegister> vRegister = clsBankClients::LoadRegistersFromFileToVector();

		clsHeader::HeaderOfScreen("Transfer Registers Screen", to_string(vRegister.size()) + " Register");

		cout << "      Date - Time      |  Acc.num1  |  Acc.num2  |  Amount  | Acc.num1 Balance '$' | Acc.num2 Balance '$' | Current User";
		cout << "\n------------------------------------------------------------------------------------------------------------------------\n";

		for (int i = 0; i < vRegister.size(); i++)
		{
			cout << setw(21) << vRegister[i].dateAndtime << "  |";
			cout << setw(8) << vRegister[i].accNum1 << "    |";
			cout << setw(8) << vRegister[i].accNum2 << "    |";
			cout << setw(6) << vRegister[i].amount << "    |";
			cout << setw(12) << vRegister[i].balance1 << "          |";
			cout << setw(12) << vRegister[i].balance2 << "          |";
			cout << setw(10) << vRegister[i].currentUser << '\n';
		}
	}
};