#pragma once
#include <iostream>
#include "clsHeader.h"
#include "clsShowCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrenciesCalculatorScreen.h"
using namespace std;

class clsShowCurrenciesScreen : protected clsHeader
{
	enum _enOperation { List = 1, Find = 2, Update = 3, Calculator = 4, MainMenue = 5 };

	static short _ReadChoice()
	{
		cout << "Choose what do you want to do?[1-5] ";
		int choice = clsInputValidate::ReadNumberBetween<int>("Invalid, please enter a correct value: ", 1, 5);

		return choice;
	}

	static void _GoBackToCurrenciesMenue()
	{
		cout << "\nEnter any key to return to 'Currencies Screen' ...";
		system("pause > 0");
		system("cls");
		ShowCurrenciesScreen();
	}

	static void _ShowCurrenciesListScreen()
	{
		clsShowCurrenciesListScreen::ShowCurrenciesList();
	}

	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::FindCurrency();
	}

	static void _ShowUpdateCurrencyScreen()
	{
		clsUpdateCurrencyScreen::UpdateCurrency();
	}

	static void _ShowCurrenciesCalculatorScreen()
	{
		clsCurrenciesCalculatorScreen::CurrenciesCalculator();
	}

	static void _PerformCurrenciesSystem(_enOperation operation)
	{
		switch (operation)
		{

		case _enOperation::List:
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrenciesMenue();
			break;

		case _enOperation::Find:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrenciesMenue();
			break;

		case _enOperation::Update:
			system("cls");
			_ShowUpdateCurrencyScreen();
			_GoBackToCurrenciesMenue();
			break;

		case _enOperation::Calculator:
			system("cls");
			_ShowCurrenciesCalculatorScreen();
			_GoBackToCurrenciesMenue();
			break;

		case _enOperation::MainMenue:
			system("cls");
		}
	}

public:

	static void ShowCurrenciesScreen()
	{
		clsHeader::HeaderOfScreen("Currencies Exchange Screen");

		cout << "------------------------------------------\n";
		cout << "         Currencies Exchange Menue\n";
		cout << "------------------------------------------";
		cout << "\n            [1] Currencies List";
		cout << "\n            [2] Find Currency";
		cout << "\n            [3] Update Currency";
		cout << "\n            [4] Currencies Calculator";
		cout << "\n            [5] Main Menue";
		cout << "\n------------------------------------------\n";

		_PerformCurrenciesSystem(_enOperation(_ReadChoice()));
	}
};