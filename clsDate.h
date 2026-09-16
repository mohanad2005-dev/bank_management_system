#pragma once
#pragma warning (disable:4996)

#include <iostream>
#include <string>
#include <ctime>
#include "clsString.h"
using namespace std;

class clsDate
{
	struct _stDate
	{
		short day, month, year;
	};

public:

	_stDate date;

	clsDate()
	{
		time_t t = time(0);
		tm* time = localtime(&t);

		date.day = time->tm_mday;
		date.month = time->tm_mon + 1;
		date.year = time->tm_year + 1900;
	}

	clsDate(string strdate)
	{
		vector <string> sVector = clsString::Split(strdate, "/");

		date.day = stoi(sVector[0]);
		date.month = stoi(sVector[1]);
		date.year = stoi(sVector[2]);
	}

	clsDate(short day, short month, short year)
	{
		date.day = day;
		date.month = month;
		date.year = year;
	}

	clsDate(short days, short year)
	{
		date.day = 1;
		date.month = 1;
		date.year = year;

		for (short i = 1; i < days; i++)
		{
			NextDay();
		}
	}

	void setDay(short day)
	{
		date.day = day;
	}

	short getDay()
	{
		return date.day;
	}

	_declspec(property(get = getDay, put = setDay)) short Day;

	void setMonth(short month)
	{
		date.month = month;
	}

	short getMonth()
	{
		return date.month;
	}

	_declspec(property(get = getMonth, put = setMonth)) short Month;

	void setYear(short year)
	{
		date.year = year;
	}

	short getYear()
	{
		return date.year;
	}

	_declspec(property(get = getYear, put = setYear)) short Year;

	static bool IsLeapYear(short year)
	{
		return (year % 400 == 0) ? true : (year % 4 == 0 && year % 100 != 0) ? true : false;
	}

	bool IsLeapYear()
	{
		return IsLeapYear(date.year);
	}

	static short YearDays(short year)
	{
		return (IsLeapYear(year)) ? 366 : 365;
	}

	short YearDays()
	{
		return YearDays(date.year);
	}

	static int YearHours(short year)
	{
		return YearDays(year) * 24;
	}

	int YearHours()
	{
		return YearHours(date.year);
	}

	static int YearMinutes(short year)
	{
		return YearHours(year) * 60;
	}

	int YearMinutes()
	{
		return YearMinutes(date.year);
	}

	static int YearSeconds(short year)
	{
		return YearMinutes(year) * 60;
	}

	int YearSeconds()
	{
		return YearSeconds(date.year);
	}

	static short MonthDays(short month, short year)
	{
		short days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		return (IsLeapYear(year) && month == 2) ? 29 : days[month - 1];
	}

	short MonthDays()
	{
		return MonthDays(date.month, date.year);
	}

	static int MonthHours(short month, short year)
	{
		return MonthDays(month, year) * 24;
	}

	int MonthHours()
	{
		return MonthHours(date.month, date.year);
	}

	static int MonthMinutes(short month, short year)
	{
		return MonthHours(month, year) * 60;
	}

	int MonthMinutes()
	{
		return MonthMinutes(date.month, date.year);
	}

	static int MonthSeconds(short month, short year)
	{
		return MonthMinutes(month, year) * 60;
	}

	int MonthSeconds()
	{
		return MonthSeconds(date.month, date.year);
	}

	static int DayHours()
	{
		return 24;
	}

	static int DayMinutes()
	{
		return DayHours() * 60;
	}

	static int DaySeconds()
	{
		return DayMinutes() * 60;
	}

	static string MonthName(short month)
	{
		string Months[12] = { "January", "February", "March", "April","May", "June", "July", "August",
			"September", "October", "November", "December" };

		return Months[month - 1];
	}

	string MonthName()
	{
		return MonthName(date.month);
	}

	static short DayOrderInWeek(short day, short month, short year)
	{
		short a = (14 - month) / 12;
		short y = year - a;
		short m = month + (12 * a) - 2;

		short d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		return d;
	}

	short DayOrderInWeek()
	{
		return DayOrderInWeek(date.day, date.month, date.year);
	}

	static string DayName(short day, short month, short year)
	{
		string Days[7] = { "Sunday", "Monday", "Tuesday", "Wednesday",
			"Thursday", "Friday", "Saturday" };

		return Days[DayOrderInWeek(day, month, year)];
	}

	string DayName()
	{
		return DayName(date.day, date.month, date.year);
	}

	static void PrintMonthCalendar(short month, short year)
	{
		cout << "----------- " << MonthName(month) << '[' << year << "] ------------\n\n";
		cout << "Sun   Mon   Tue   Wed   Thu   Fri   Sat\n";

		short count = 0;

		for (short i = 0; i < DayOrderInWeek(1, month, year); i++)
		{
			cout << "      ";
			count++;
		}

		for (short i = 1; i <= MonthDays(month, year); i++)
		{
			if (count == 7)
			{
				cout << '\n';
				count = 0;
			}

			printf("%0*d    ", 2, i);

			count++;
		}

		cout << "\n\n";
	}

	void PrintMonthCalendar()
	{
		PrintMonthCalendar(date.month, date.year);
	}

	static void PrintYearCalendar(short year)
	{
		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, year);
		}
	}

	void PrintYearCalendar()
	{
		PrintYearCalendar(date.year);
	}

	static bool IsValidDate(clsDate date)
	{
		return (date.date.day < 1 || date.date.day > MonthDays(date.date.month, date.date.year) || date.date.month < 1 || date.date.month > 12 || date.date.year < 0) ? false : true;
	}

	bool IsValidDate()
	{
		return IsValidDate(*this);
	}

	static bool IsDate1BeforeDate2(clsDate date1, clsDate date2)
	{
		return ((date1.date.year < date2.date.year) || ((date1.date.year == date2.date.year) && (date1.date.month < date2.date.month)) || ((date1.date.year == date2.date.year) && (date1.date.month == date2.date.month) && (date1.date.day < date2.date.day))) ? true : false;
	}

	bool IsDate1BeforeDate2(clsDate date2)
	{
		return IsDate1BeforeDate2(*this, date2);
	}

	static bool IsDate1AfterDate2(clsDate date1, clsDate date2)
	{
		return ((date1.date.year > date2.date.year) || ((date1.date.year == date2.date.year) && (date1.date.month > date2.date.month)) || ((date1.date.year == date2.date.year) && (date1.date.month == date2.date.month) && (date1.date.day > date2.date.day))) ? true : false;
	}

	bool IsDate1AfterDate2(clsDate date2)
	{
		return IsDate1BeforeDate2(*this, date2);
	}

	static bool IsDate1EqualDate2(clsDate date1, clsDate date2)
	{
		return (date1.date.year == date2.date.year) && (date1.date.month == date2.date.month) && (date1.date.day == date2.date.day);
	}

	bool IsDate1EqualDate2(clsDate date2)
	{
		return IsDate1BeforeDate2(*this, date2);
	}

	void NextDay(short& day, short& month, short& year)
	{
		if (day == MonthDays(month, year))
		{
			if (month == 12)
			{
				day = 1;
				month = 1;
				year++;
			}
			else
			{
				day = 1;
				month++;
			}
		}
		else
			day++;
	}

	void NextDay()
	{
		if (date.day == MonthDays(date.month, date.year))
		{
			if (date.month == 12)
			{
				date.day = 1;
				date.month = 1;
				date.year++;
			}
			else
			{
				date.day = 1;
				date.month++;
			}
		}
		else
			date.day++;
	}

	void IncreaseByXDays(short days)
	{
		for (short i = 0; i < days; i++)
		{
			NextDay();
		}
	}

	void NextWeek()
	{
		for (short i = 0; i < 7; i++)
		{
			NextDay();
		}
	}

	void IncreaseByXWeeks(short weeks)
	{
		for (short i = 0; i < weeks; i++)
		{
			NextWeek();
		}
	}

	void NextMonth()
	{
		short times = MonthDays();

		for (short i = 0; i < times; i++)
		{
			NextDay();
		}
	}

	void IncreaseByXMonths(short months)
	{
		for (short i = 0; i < months; i++)
		{
			NextMonth();
		}
	}

	void NextYear()
	{
		for (short i = 0; i < 12; i++)
		{
			NextMonth();
		}
	}

	void IncreaseByXYears(short years)
	{
		for (short i = 0; i < years; i++)
		{
			NextYear();
		}
	}

	void NextDecade()
	{
		for (short i = 0; i < 10; i++)
		{
			NextYear();
		}
	}

	void IncreaseByXDecades(short decades)
	{
		for (short i = 0; i < decades; i++)
		{
			NextDecade();
		}
	}

	void NextCentury()
	{
		for (short i = 0; i < 10; i++)
		{
			NextDecade();
		}
	}

	void IncreaseByXCenturies(short centuries)
	{
		for (short i = 0; i < centuries; i++)
		{
			NextCentury();
		}
	}

	void NextMillennium()
	{
		for (short i = 0; i < 10; i++)
		{
			NextCentury();
		}
	}

	void IncreaseByXMillenniums(short millenium)
	{
		for (short i = 0; i < millenium; i++)
		{
			NextMillennium();
		}
	}

	void PreviousDay()
	{
		if (date.day == 1)
		{
			if (date.month == 1)
			{
				date.day = 31;
				date.month = 12;
				date.year--;
			}
			else
			{
				date.month--;
				date.day = MonthDays(date.month, date.year);
			}
		}
		else
			date.day--;
	}

	void DecreaseByXDays(short days)
	{
		for (short i = 0; i < days; i++)
		{
			PreviousDay();
		}
	}

	void PreviousWeek()
	{
		for (short i = 0; i < 7; i++)
		{
			PreviousDay();
		}
	}

	void DecreaseByXWeeks(short weeks)
	{
		for (short i = 0; i < weeks; i++)
		{
			PreviousWeek();
		}
	}

	void PreviousMonth()
	{
		short m = 0;

		if (date.month == 1)
			m = 12;
		else
			m = date.month - 1;

		short times = MonthDays(m, date.year);

		for (short i = 0; i < times; i++)
		{
			PreviousDay();
		}
	}

	void DecreaseByXMonths(short months)
	{
		for (short i = 0; i < months; i++)
		{
			PreviousMonth();
		}
	}

	void PreviousYear()
	{
		for (short i = 0; i < 12; i++)
		{
			PreviousMonth();
		}
	}

	void DecreaseByXYears(short years)
	{
		for (short i = 0; i < years; i++)
		{
			PreviousYear();
		}
	}

	void PreviousDecade()
	{
		for (short i = 0; i < 10; i++)
		{
			PreviousYear();
		}
	}

	void DecreaseByXDecades(short decades)
	{
		for (short i = 0; i < decades; i++)
		{
			PreviousDecade();
		}
	}

	void PreviousCentury()
	{
		for (short i = 0; i < 10; i++)
		{
			PreviousDecade();
		}
	}

	void DecreaseByXCenturies(short centuries)
	{
		for (short i = 0; i < centuries; i++)
		{
			PreviousCentury();
		}
	}

	void PreviousMillennium()
	{
		for (short i = 0; i < 10; i++)
		{
			PreviousCentury();
		}
	}

	void DecreaseByXMillenniums(short millenium)
	{
		for (short i = 0; i < millenium; i++)
		{
			PreviousMillennium();
		}
	}

	static short DaysFromTheBegining(clsDate date2)
	{
		clsDate d;
		short count = 0;

		clsDate date1;
		date1.date.day = 1;
		date1.date.month = 1;
		date1.date.year = date2.date.year;

		if (!IsDate1BeforeDate2(date1, date2) || IsDate1EqualDate2(date1, date2))
			return 0;

		while (IsDate1BeforeDate2(date1, date2))
		{
			d.NextDay(date1.date.day, date1.date.month, date1.date.year);

			count++;
		}

		return count + 1;
	}

	short DaysFromTheBegining()
	{
		return DaysFromTheBegining(*this);
	}

	static short CalculateMyAgeInDays(short day, short month, short year)
	{
		clsDate d;

		short count = 0;

		clsDate date1;
		date1.date.day = day;
		date1.date.month = month;
		date1.date.year = year;

		time_t t = time(0);
		tm* time = localtime(&t);

		clsDate date2;
		date2.date.day = time->tm_mday;
		date2.date.month = time->tm_mon + 1;
		date2.date.year = time->tm_year + 1900;

		while (d.IsDate1BeforeDate2(date1, date2))
		{
			d.NextDay(date1.date.day, date1.date.month, date1.date.year);

			count++;
		}

		return count;
	}

	static string GetDateFromDayOrderInYear(short day_ord, short year)
	{
		clsDate d;

		short day = 1, month = 1;

		for (short i = 1; i < day_ord; i++)
		{
			d.NextDay(day, month, year);
		}

		return to_string(day) + '/' + to_string(month) + '/' + to_string(year);
	}

	static bool IsEndOfWeek(short day, short month, short year)
	{
		return DayOrderInWeek(day, month, year) == 6;
	}

	bool IsEndOfWeek()
	{
		return IsEndOfWeek(date.day, date.month, date.year);
	}

	static bool IsWeekend(short day, short month, short year)
	{
		short order = DayOrderInWeek(day, month, year);

		return order == 5 || order == 6;
	}

	bool IsWeekend()
	{
		return IsWeekend(date.day, date.month, date.year);
	}

	static bool IsBusinessDay(short day, short month, short year)
	{
		return !IsWeekend(day, month, year);
	}

	bool IsBusinessDay()
	{
		return IsBusinessDay(date.day, date.month, date.year);
	}

	static short DaysUntilEndOfYear(clsDate date1)
	{
		clsDate d;
		short count = 0;

		clsDate date2;
		date2.date.day = 31;
		date2.date.month = 12;
		date2.date.year = date1.date.year;

		while (IsDate1BeforeDate2(date1, date2))
		{
			d.NextDay(date1.date.day, date1.date.month, date1.date.year);

			count++;
		}

		return count;
	}

	short DaysUntilEndOfYear()
	{
		return DaysUntilEndOfYear(*this);
	}

	static short DaysUntilEndOfMonth(short day, short month, short year)
	{
		return MonthDays(month, year) - day;
	}

	short DaysUntilEndOfMonth()
	{
		return DaysUntilEndOfMonth(date.day, date.month, date.year);
	}

	static short DaysUntilEndOfWeek(short day, short month, short year)
	{
		return 6 - DayOrderInWeek(day, month, year);
	}

	short DaysUntilEndOfWeek()
	{
		return DaysUntilEndOfWeek(date.day, date.month, date.year);
	}

	static void SwapDates(clsDate& date1, clsDate& date2)
	{
		clsDate temp;

		temp = date1;
		date1 = date2;
		date2 = temp;
	}

	void SwapDates(clsDate& date2)
	{
		SwapDates(*this, date2);
	}

	static short DifferenceInDays(clsDate date1, clsDate date2)
	{
		clsDate d;
		short count = 0;

		if (IsDate1BeforeDate2(date1, date2))
		{
			while (IsDate1BeforeDate2(date1, date2))
			{
				d.NextDay(date1.date.day, date1.date.month, date1.date.year);

				count++;
			}
		}
		else if (IsDate1BeforeDate2(date2, date1))
		{
			while (IsDate1BeforeDate2(date2, date1))
			{
				d.NextDay(date2.date.day, date2.date.month, date2.date.year);

				count++;
			}
		}

		return count;
	}

	static short CalculateVacationDays(clsDate date1, clsDate date2)
	{
		clsDate d;
		short count = 0;

		if (IsDate1BeforeDate2(date1, date2))
		{
			while (IsDate1BeforeDate2(date1, date2))
			{
				d.NextDay(date1.date.day, date1.date.month, date1.date.year);

				if (!IsBusinessDay(date1.date.day, date1.date.month, date1.date.year))
					count++;
			}
		}
		else if (IsDate1BeforeDate2(date2, date1))
		{
			while (IsDate1BeforeDate2(date2, date1))
			{
				d.NextDay(date2.date.day, date2.date.month, date2.date.year);

				if (!IsBusinessDay(date2.date.day, date2.date.month, date2.date.year))
					count++;
			}
		}

		return count;
	}

	short CalculateVacationDays(clsDate date2)
	{
		return CalculateVacationDays(date2, *this);
	}

	void PrintDate()
	{
		printf("Date: %0*d/%0*d/%0*d\n", 2, date.day, 2, date.month, 4, date.year);
	}

	static string DateAndTime()
	{
		time_t t = time(0);
		tm* time = localtime(&t);

		return to_string(time->tm_mday) + '/' + to_string(time->tm_mon + 1) + '/' + to_string(time->tm_year + 1900)
			+ " - " + to_string(time->tm_hour) + ':' + to_string(time->tm_min) + ':' + to_string(time->tm_sec);
	}
};