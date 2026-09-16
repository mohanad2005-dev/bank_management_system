#pragma once
#include <iostream>
#include <vector>
using namespace std;

class clsString
{
	string _Value;

public:

	clsString()
	{
		_Value = "";
	}

	clsString(string value)
	{
		_Value = value;
	}

	void setValue(string value)
	{
		_Value = value;
	}

	string getValue()
	{
		return _Value;
	}

	_declspec(property(get = getValue, put = setValue)) string Text;

	static short Length(string text)
	{
		return text.length();
	}

	short Length()
	{
		return Length(_Value);
	}

	static short CountWords(string text)
	{
		string delim = " ";
		short pos = 0;
		string sText;
		short counter = 0;

		while ((pos = text.find(delim)) != string::npos)
		{
			sText = text.substr(0, pos);

			if (sText != "")
				counter++;

			text.erase(0, pos + delim.length());
		}

		if (text != "")
			counter++;

		return counter;
	}

	short CountWords()
	{
		return CountWords(_Value);
	}

	static short CountLetters(string text)
	{
		short count = 0;

		for (short i = 0; i < text.length(); i++)
		{
			if (islower(text[i]) || isupper(text[i]))
				count++;
		}

		return count;
	}

	short CountLetters()
	{
		return CountLetters(_Value);
	}

	static short CountCapitalLetters(string text)
	{
		short count = 0;

		for (short i = 0; i < text.length(); i++)
		{
			if (isupper(text[i]))
				count++;
		}

		return count;
	}

	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	static short CountSmallLetters(string text)
	{
		short count = 0;

		for (short i = 0; i < text.length(); i++)
		{
			if (islower(text[i]))
				count++;
		}

		return count;
	}

	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}

	static short CountSpecificLetters(string text, char letter, bool matchcase)
	{
		short count = 0;

		if (matchcase)
		{
			for (short i = 0; i < text.length(); i++)
			{
				if (tolower(text[i]) == tolower(letter))
					count++;
			}
		}
		else
		{
			for (short i = 0; i < text.length(); i++)
			{
				if (text[i] == letter)
					count++;
			}
		}

		return count;
	}

	short CountSpecificLetters(char letter, bool matchcase)
	{
		return CountSpecificLetters(_Value, letter, matchcase);
	}

	static short CountVowels(string text)
	{
		short count = 0;

		for (short i = 0; i < text.length(); i++)
		{
			text[i] = tolower(text[i]);

			if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u')
				count++;
		}

		return count;
	}

	short CountVowels()
	{
		return CountVowels(_Value);
	}

	static string CapitalLetters(string text)
	{
		for (short i = 0; i < text.length(); i++)
		{
			if (islower(text[i]))
				text[i] = toupper(text[i]);
		}

		return text;
	}

	string CapitalLetters()
	{
		return CapitalLetters(_Value);
	}

	static string SmallLetters(string text)
	{
		for (short i = 0; i < text.length(); i++)
		{
			if (isupper(text[i]))
				text[i] = tolower(text[i]);
		}

		return text;
	}

	string SmallLetters()
	{
		return SmallLetters(_Value);
	}

	static string InvertLettersCase(string text)
	{
		for (short i = 0; i < text.length(); i++)
		{
			if (isupper(text[i]))
				text[i] = tolower(text[i]);

			else if (islower(text[i]))
				text[i] = toupper(text[i]);
		}

		return text;
	}

	string InvertLettersCase()
	{
		return InvertLettersCase(_Value);
	}

	static string JoinString(string arr[], short length)
	{
		string Text = "";

		for (short i = 0; i < length; i++)
		{
			Text += arr[i];

			if (i == length - 2)
				Text += " and ";
			else if (i != length - 1)
				Text += ", ";
		}

		return Text;
	}

	static string UpperFirstLetterOfEachWord(string text)
	{
		bool isFirstLetter = true;
		string delim = " ";

		text.erase(0, delim.length() - 1);

		for (short i = 0; i < text.length(); i++)
		{
			if (isFirstLetter && text[i] != ' ')
				text[i] = toupper(text[i]);

			isFirstLetter = (text[i] == ' ') ? true : false;
		}

		return text;
	}

	string UpperFirstLetterOfEachWord()
	{
		return UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string text)
	{
		bool isFirstLetter = true;
		string delim = " ";

		text.erase(0, delim.length() - 1);

		for (short i = 0; i < text.length(); i++)
		{
			if (isFirstLetter && text[i] != ' ')
				text[i] = tolower(text[i]);

			isFirstLetter = (text[i] == ' ') ? true : false;
		}

		return text;
	}

	string LowerFirstLetterOfEachWord()
	{
		return LowerFirstLetterOfEachWord(_Value);
	}

	static string RemovePunctuations(string text)
	{
		string sText = "";

		for (short i = 0; i < text.length(); i++)
		{
			if (!ispunct(text[i]))
				sText += text[i];
		}

		return sText;
	}

	string RemovePunctuations()
	{
		return RemovePunctuations(_Value);
	}

	static string ReplaceWord(string text, string old_word, string new_word)
	{
		text.replace(text.find(old_word), old_word.length(), new_word);

		return text;
	}

	string ReplaceWord(string old_word, string new_word)
	{
		return ReplaceWord(_Value, old_word, new_word);
	}

	static string ReverseWordsInString(string text)
	{
		vector <string> words;

		string sText = "";
		string delim = " ";
		string sWord;
		short pos = 0;

		while ((pos = text.find(delim)) != string::npos)
		{
			sWord = text.substr(0, pos);

			words.push_back(sWord);

			text.erase(0, pos + delim.length());
		}

		words.push_back(text);

		for (short i = words.size() - 1; i >= 0; i--)
		{
			sText = sText + words[i] + " ";
		}

		return sText;
	}

	string ReverseWordsInString()
	{
		return ReverseWordsInString(_Value);
	}

	static vector <string> Split(string text, string seperator)
	{
		vector <string> words;
		string sWord = "";
		short pos = 0;

		while ((pos = text.find(seperator)) != string::npos)
		{
			sWord = text.substr(0, pos);

			words.push_back(sWord);

			text.erase(0, pos + seperator.length());
		}

		if (text != "")
			words.push_back(text);

		return words;
	}

	vector <string> Split(string seperator)
	{
		return Split(_Value, seperator);
	}

	static string Trim_Left(string text)
	{
		while (text[0] == ' ')
			text.erase(0, 1);

		return text;
	}

	string Trim_Left()
	{
		return Trim_Left(_Value);
	}

	static string Trim_Rigth(string text)
	{
		short length = text.length();
		char delim = ' ';

		while (text[length - 1] == delim)
		{
			text.pop_back();
			length = text.length();
		}

		return text;
	}

	string Trim_Rigth()
	{
		return Trim_Rigth(_Value);
	}

	static string Trim(string text)
	{
		return Trim_Left(Trim_Rigth(text));
	}

	string Trim()
	{
		return Trim(_Value);
	}

	static string NumberToString(int num)
	{
		string num_words = "";

		if (num == 0)
			return "Zero";

		if (num < 0)
		{
			num_words += "minus ";
			num *= -1;
		}

		string ones[20] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
			"Eleven", "Twelve", "Thirteen", "Fourteen","Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };

		string tens[10] = { "", "", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eigthty", "Ninety" };

		if (num >= 0 && num <= 19)
			num_words += ones[num];
		else if (num >= 20 && num <= 99)
			num_words += tens[num / 10] + ' ' + ones[num % 10];
		else if (num >= 100 && num <= 999)
		{
			num_words += NumberToString(num / 100) + " Hundered " + ((num % 100 != 0) ? NumberToString(num % 100) : "");
		}
		else if (num >= 1000 && num <= 999999)
		{
			num_words += NumberToString(num / 1000) + " Thousand " + ((num % 1000 != 0) ? "and " + NumberToString(num % 1000) : "");
		}
		else if (num >= 1000000 && num <= 999999999)
		{
			num_words += NumberToString(num / 1000000) + " Million " + ((num % 1000000 != 0) ? "and " + NumberToString(num % 1000000) : "");
		}
		else
		{
			num_words += NumberToString(num / 1000000000) + " Billion " + ((num % 1000000000 != 0) ? "and " + NumberToString(num % 1000000000) : "");
		}

		return num_words;
	}
};