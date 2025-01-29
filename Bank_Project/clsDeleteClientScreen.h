#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDeleteClientScreen : protected clsScreen
{
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
	static void showDeleteCleintScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;// this will exit the function and it will not continue
		}

		_DrawScreenHeader("\t Delete Client Screeen");
		string AccountNumber = "";


		cout << "\nPlease Enter client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		char deleteClient = 'n';
		cout << "\nAre You Sure You Want To Delete This Client y/n ? ";
		cin >> deleteClient;

		if (deleteClient == 'y')
		{
			if (Client1.Delete())
			{
				cout << "\nClient Deleted Successfully :)\n";
				_PrintClient(Client1);
			}
			else
			{
				cout << "\nError Client was not Deleted\n";
			}
		}
	}
};

