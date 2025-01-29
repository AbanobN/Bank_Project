#pragma once
#include <iostream>
#include <string>
using namespace std;


class clsPerson
{
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:
	// Constractor
	clsPerson(string firstName, string lastName, string email, string phone)
	{
		_FirstName = firstName;
		_LastName = lastName;
		_Email = email;
		_Phone = phone;
	}

	// Setters 
	void setFirstName(string firstName)
	{
		_FirstName = firstName;
	}
	void setLastName(string lastName)
	{
		_LastName = lastName;
	}
	void setEmail(string email)
	{
		_Email = email;
	}
	void setPhone(string phone)
	{
		_Phone = phone;
	}

	// Getters 
	string getFirstName()
	{
		return _FirstName;
	}
	string getLastName()
	{
		return _LastName;
	}
	string getEmail()
	{
		return _Email;
	}
	string getPhone()
	{
		return _Phone;
	}

	// Properties
	__declspec(property(get = getFirstName, put = setFirstName)) string FirstName;
	__declspec(property(get = getLastName, put = setLastName)) string LastName;
	__declspec(property(get = getEmail, put = setEmail)) string Email;
	__declspec(property(get = getPhone, put = setPhone)) string Phone;

	// Other Methods
	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

};

