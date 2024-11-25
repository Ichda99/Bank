#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsString.h"
#include "clsPerson.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;

	static clsBankClient _ConvertLineToClientObject(string Line,string Seperator = "#//#")
	{
		vector <string> vClientData;

		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3],
			vClientData[4], vClientData[5], stod(vClientData[6]));
	}

	static clsBankClient _GetEmptyObjectClient()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode,
		float AccountBalance) : clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	//Setter
	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	//Getter
	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(put = SetPinCode, get = GetPinCode)) string PinCode;

	//Setter
	void SetAccountBalance(float AccountBlance)
	{
		_AccountBalance = AccountBlance;
	}

	//Getter
	float GetAccountBlance()
	{
		return _AccountBalance;
	}

	__declspec(property(put = SetAccountBalance, get = GetAccountBlance)) float AccountBalance;

	void Print()
	{
		cout << "\nClient Details: ";
		cout << "\n---------------------------------";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFullName    : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPinCode     : " << _PinCode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n---------------------------------\n";
	}

	static clsBankClient Find(string AccountNumber)
	{
		vector <clsBankClient> vClients;

		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);// Read Mode

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile,Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}

			MyFile.close();
		}

		return _GetEmptyObjectClient();

	}

	static clsBankClient Find(string AccountNumber,string PinCode)
	{
		vector <clsBankClient> vClients;

		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);// Read Mode

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}

			MyFile.close();
		}

		return _GetEmptyObjectClient();

	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		return (!Client1.IsEmpty());
	}

};

