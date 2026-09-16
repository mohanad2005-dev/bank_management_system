#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "clsString.h"
using namespace std;

const string File = "CurrenciesFile.txt";

class clsBankCurrencies
{
	string _Country, _CurrencyCode, _CurrencyName;
	float _Rate;

	enum enMode { Empty = 0, Update = 1 };
	enMode _Mode;

	static clsBankCurrencies _ConvertLineToCurrencyRecord(string line)
	{
		vector <string> Currency = clsString::Split(line, "#//#");

		return clsBankCurrencies(enMode::Update, Currency[0], Currency[1], Currency[2], stof(Currency[3]));
	}

	static clsBankCurrencies _GetEmptyCurrencyObject()
	{
		return clsBankCurrencies(enMode::Empty, "", "", "", 0);
	}

	string ConvertCurrencyRecordToLine(clsBankCurrencies Currency)
	{
		string line = "";

		line += Currency.Country();
		line += "#//#";
		line += Currency.CurrencyCode();
		line += "#//#";
		line += Currency.CurrencyName();
		line += "#//#";
		line += to_string(Currency.Rate);

		return line;
	}

	void _SaveCurrenciesDateInFile(vector <clsBankCurrencies> vCurrencies)
	{
		fstream file;
		file.open(File, ios::out);

		if (file.is_open())
		{
			for (clsBankCurrencies Currency : vCurrencies)
			{
				file << ConvertCurrencyRecordToLine(Currency) << endl;
			}

			file.close();
		}
	}

public:

	clsBankCurrencies(enMode mode, string country, string currencyCode, string currencyName, float rate)
	{
		_Mode = mode;
		_Country = country;
		_CurrencyCode = currencyCode;
		_CurrencyName = currencyName;
		_Rate = rate;
	}

	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	void setRate(float rate)
	{
		_Rate = rate;
	}

	float getRate()
	{
		return _Rate;
	}

	__declspec(property(get = getRate, put = setRate)) float Rate;

	static vector <clsBankCurrencies> LoadCurrenciesDataFromFileToVector()
	{
		vector <clsBankCurrencies> vCurrencies;

		fstream file;
		file.open(File, ios::in);

		if (file.is_open())
		{
			string line;

			while (getline(file, line))
			{
				vCurrencies.push_back(_ConvertLineToCurrencyRecord(line));
			}

			file.close();
		}

		return vCurrencies;
	}

	void PrintCurrencyCard()
	{
		cout << "      Currency Card";
		cout << "\n-------------------------";
		cout << "\nCountry      : " << _Country;
		cout << "\nCurrency Code: " << _CurrencyCode;
		cout << "\nCurrency Name: " << _CurrencyName;
		cout << "\nRate (1$)    = " << _Rate;
		cout << "\n-------------------------";
	}

	static clsBankCurrencies FindByCode(string CurrencyCode)
	{
		vector <clsBankCurrencies> vCurrencies = LoadCurrenciesDataFromFileToVector();

		for (clsBankCurrencies Currency : vCurrencies)
		{
			if (Currency.CurrencyCode() == clsString::CapitalLetters(CurrencyCode))
				return Currency;
		}

		return _GetEmptyCurrencyObject();
	}

	static clsBankCurrencies FindByCountry(string Country)
	{
		vector <clsBankCurrencies> vCurrencies = LoadCurrenciesDataFromFileToVector();

		for (clsBankCurrencies Currency : vCurrencies)
		{
			if (Currency.Country() == clsString::UpperFirstLetterOfEachWord(Country))
				return Currency;
		}

		return _GetEmptyCurrencyObject();
	}

	bool IsEmpty()
	{
		return _Mode == enMode::Empty;
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsBankCurrencies Currency = clsBankCurrencies::FindByCode(CurrencyCode);

		return Currency.IsEmpty();
	}

	void UpdateRate(float newRate)
	{
		vector <clsBankCurrencies> vCurrencies = LoadCurrenciesDataFromFileToVector();

		for (clsBankCurrencies& Currency : vCurrencies)
		{
			if (Currency.CurrencyCode() == this->_CurrencyCode)
			{
				Currency.Rate = newRate;
				this->Rate = newRate;

				_SaveCurrenciesDateInFile(vCurrencies);

				break;
			}
		}
	}
};