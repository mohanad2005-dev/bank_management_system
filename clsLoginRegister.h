#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
#include "clsUtil.h"
using namespace std;

class clsLoginRegister
{
public:

	static void SaveInLoginRegisterFile(string username, string pass, int permissions)
	{
		string Register = clsDate::DateAndTime() + "#//#" + username + "#//#" + clsUtil::EncryptText(pass, 3) + "#//#" + to_string(permissions);

		fstream file;
		file.open("LoginRegisterFile.txt", ios::app | ios::out);

		if (file.is_open())
		{
			file << Register << endl;

			file.close();
		}
	}
};