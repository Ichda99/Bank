#pragma once

#include <iostream>

using namespace std;

class clsPerson
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:

	clsPerson(string FirstName, string LastName, string Email, string Phone)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}

	//Setter
	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}

	//Getter
	string GetFirstName()
	{
		return _FirstName;
	}

	__declspec(property(put = SetFirstName, get = GetFirstName)) string FirstName;

	//Setter
	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}

	//Getter
	string GetLastName()
	{
		return _LastName;
	}

	__declspec(property(put = SetLastName, get = GetLastName)) string LastName;

	//Setter
	void SetEmail(string Email)
	{
		_Email = Email;
	}

	//Getter
	string GetEmail()
	{
		return _Email;
	}

	__declspec(property(put = SetEmail, get = GetEmail)) string Email;

	//Setter
	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}

	//Getter
	string GetPhone()
	{
		return _Phone;
	}

	__declspec(property(put = SetPhone, get = GetPhone)) string Phone;

	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

};


