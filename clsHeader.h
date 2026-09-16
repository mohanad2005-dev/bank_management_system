#pragma once
#include <iostream>
#include "clsDate.h"
#include "Global.h"
using namespace std;

class clsHeader
{
public:

	static void HeaderOfScreen(string title, string subTitle = "")
	{
		cout << "==========================================\n";
		cout << "               " << title << '\n';

		if (subTitle != "")
			cout << "               " << subTitle << '\n';

		cout << "==========================================\n";

		cout << "User: " << CurrentUser.Username << '\n';

		clsDate date;
		date.PrintDate();

		cout << "----------------\n\n";
	}
};