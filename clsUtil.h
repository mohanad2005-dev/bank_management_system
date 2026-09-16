#pragma once
#include <iostream>
#include "clsDate.h"
using namespace std;

class clsUtil
{
public:

	enum enType { Small = 1, Capital = 2, Digit = 3, Special = 4, Mix = 5 };

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int from, int to)
	{
		return rand() % (to - from + 1) + from;
	}

	static char RandomCharacter(enType type)
	{
		short n = 0;

		if (type == enType::Mix)
		{
			n = RandomNumber(1, 4);
			type = enType(n);
		}

		switch (type)
		{
		case enType::Capital:
			return char(RandomNumber(65, 90));
		case enType::Small:
			return char(RandomNumber(97, 122));
		case enType::Digit:
			return char(RandomNumber(48, 57));
		case enType::Special:
			return char(RandomNumber(33, 47));
		}
	}

	static string GenerateWord(enType type, short length)
	{
		string word = "";

		for (short i = 0; i < length; i++)
		{
			word += RandomCharacter(type);
		}

		return word;
	}

	static string GenerateKey(enType type, short length)
	{
		string key = "";

		for (short i = 0; i < length; i++)
		{
			key += GenerateWord(type, 4);

			if (i != length - 1)
				key += '-';
		}

		return key;
	}

	static void GenerateKeys(short keys_num, enType type, short length)
	{
		for (short i = 0; i < keys_num; i++)
		{
			cout << "key[" << i + 1 << "]: " << GenerateKey(type, length) << endl;
		}
	}

	static void FillArrayWithRandomNumbers(int arr[], int length)
	{
		for (short i = 0; i < length; i++)
		{
			arr[i] = RandomNumber(1, 100);
		}
	}

	static void FillArrayWithRandomCharacters(char arr[], int length, enType type)
	{
		for (short i = 0; i < length; i++)
		{
			arr[i] = RandomCharacter(type);
		}
	}

	static void FillArrayWithRandomWords(string arr[], int length, enType type, int word_len)
	{
		for (short i = 0; i < length; i++)
		{
			arr[i] = GenerateWord(type, word_len);
		}
	}

	static void FillArrayWithRandomKeys(string arr[], int length, enType type, int key_len)
	{
		for (short i = 0; i < length; i++)
		{
			arr[i] = GenerateKey(type, key_len);
		}
	}

	static void Swap(int& a, int& b)
	{
		int temp;

		temp = a;
		a = b;
		b = temp;
	}

	static void Swap(char& a, char& b)
	{
		char temp;

		temp = a;
		a = b;
		b = temp;
	}

	static void Swap(bool& a, bool& b)
	{
		bool temp;

		temp = a;
		a = b;
		b = temp;
	}

	static void Swap(double& a, double& b)
	{
		double temp;

		temp = a;
		a = b;
		b = temp;
	}

	static void Swap(string& a, string& b)
	{
		string temp;

		temp = a;
		a = b;
		b = temp;
	}

	static void Swap(clsDate& a, clsDate& b)
	{
		clsDate temp;

		temp = a;
		a = b;
		b = temp;
	}

	static void ShuffleArray(int arr[], int length)
	{
		for (short i = 0; i < length; i++)
		{
			Swap(arr[RandomNumber(0, length - 1)], arr[RandomNumber(0, length - 1)]);
		}
	}

	static void ShuffleArray(string arr[], int length)
	{
		for (short i = 0; i < length; i++)
		{
			Swap(arr[RandomNumber(0, length - 1)], arr[RandomNumber(0, length - 1)]);
		}
	}

	static string Tabs(short tabs_num)
	{
		string tabs = "";

		for (short i = 0; i < tabs_num; i++)
		{
			tabs += "    ";
		}

		return tabs;
	}

	static string EncryptText(string& text, short enc_key)
	{
		for (short i = 0; i < text.length(); i++)
		{
			text[i] = char(int(text[i]) + enc_key);
		}

		return text;
	}

	static string DecryptText(string& text, short enc_key)
	{
		for (short i = 0; i < text.length(); i++)
		{
			text[i] = char(int(text[i]) - enc_key);
		}

		return text;
	}
};