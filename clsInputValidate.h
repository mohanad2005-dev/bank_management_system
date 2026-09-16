#pragma once
#include <iostream>
#include "clsDate.h"
#include "clsUtil.h"
using namespace std;

class clsInputValidate
{
public:

	template <typename T> static T IsNumberBetween(T num, T from, T to)
	{
		return (num >= from && num <= to) ? true : false;
	}

	static bool IsDateBetween(clsDate date, clsDate from, clsDate to)
	{
		if (clsDate::IsDate1AfterDate2(from, to))
			clsUtil::Swap(from, to);

		return ((clsDate::IsDate1AfterDate2(date, from) || clsDate::IsDate1EqualDate2(date, from)) && (clsDate::IsDate1BeforeDate2(date, to) || clsDate::IsDate1EqualDate2(date, to))) ? true : false;
	}

	template <typename T> static T ReadNumber(string error_message)
	{
		T x;

		cin >> x;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << error_message;
			cin >> x;
		}

		return x;
	}

	template <typename T> static T ReadNumberBetween(string error_message, T from, T to)
	{
		T x = ReadNumber<T>(error_message);

		while (x < from || x > to)
		{
			cout << "Enter a number depend of the period [" << from << '-' << to << "]: ";
			x = ReadNumber<T>(error_message);
		}

		return x;
	}

	static string ReadString()
	{
		string text;

		getline(cin, text);

		return text;
	}

	static bool IsValidDate(clsDate date)
	{
		return clsDate::IsValidDate(date);
	}
};