#pragma once
#include <iostream>
using namespace std;

class clsPerson
{
	string _Firstname, _Lastname, _Email, _Phone;

public:

	clsPerson(string firstname, string lastname, string email, string phone)
	{
		_Firstname = firstname;
		_Lastname = lastname;
		_Email = email;
		_Phone = phone;
	}

	void setFirstName(string firstname)
	{
		_Firstname = firstname;
	}

	string getFirstName()
	{
		return _Firstname;
	}

	__declspec(property(get = getFirstName, put = setFirstName)) string FirstName;

	void setLastName(string lastname)
	{
		_Lastname = lastname;
	}

	string getLastName()
	{
		return _Lastname;
	}

	__declspec(property(get = getLastName, put = setLastName)) string LastName;

	string FullName()
	{
		return _Firstname + " " + _Lastname;
	}

	void setEmail(string email)
	{
		_Email = email;
	}

	string getEmail()
	{
		return _Email;
	}

	__declspec(property(get = getEmail, put = setEmail)) string Email;

	void setPhone(string phone)
	{
		_Phone = phone;
	}

	string getPhone()
	{
		return _Phone;
	}

	__declspec(property(get = getPhone, put = setPhone)) string Phone;
};

