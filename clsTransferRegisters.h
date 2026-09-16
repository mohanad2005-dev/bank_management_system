#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
using namespace std;

class clsTransferRegister
{
public:

	static void SaveInTransferRegisterFile(string accNum1, string accNum2, float amount, float balance1, float balance2, string currentUser)
	{
		string Register = clsDate::DateAndTime() + "#//#" + accNum1 + "#//#" + accNum2 + "#//#" + to_string(amount) + "#//#" + to_string(balance1) + "#//#" + to_string(balance2) + "#//#" + currentUser;

		fstream file;
		file.open("TransferRegisterFile.txt", ios::app | ios::out);

		if (file.is_open())
		{
			file << Register << endl;

			file.close();
		}
	}
};