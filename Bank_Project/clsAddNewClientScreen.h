#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"

class clsAddNewClientScreen : protected clsScreen
{
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter FirstName: ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter PinCode: ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter Account Balance: ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();
	}

	static void _PrintClient(clsBankClient& Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber;
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

public:
	static void ShowAddNewClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;// this will exit the function and it will not continue
		}

		_DrawScreenHeader("\t Add New Client Screeen");
		string AccountNumber = "";

		cout << "\nPlease Enter client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Is Already Used, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient newClient = clsBankClient::GetAddClientObject(AccountNumber);

		_ReadClientInfo(newClient);
		clsBankClient::enSaveResults SaveResult;

		SaveResult = newClient.Save();

		switch (SaveResult)
		{
		case  clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nAccount Added Successfully :-)\n";
			_PrintClient(newClient);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;

		}
		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
		{
			cout << "\nError account was not saved because Account Number Is Already Exist";
			break;

		}

		}
	}
};

