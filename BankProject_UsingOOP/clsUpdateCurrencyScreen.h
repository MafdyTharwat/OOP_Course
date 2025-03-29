#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrency.h"

class clsUpdateCurrencyScreen : protected clsScreen
{
private:
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$)   : " << Currency.Rate();
        cout << "\n_____________________________\n";
    }

    static float _ReadCurrencyRate()
    {
        float NewRate = 0;
        cout << "\nEnter New Rate: ";
        NewRate = clsInputValidate::ReadFloatNumber();
        return NewRate;
    }

public:
    static void ShowUpdateCurrencyRate()
    {
        _DrawScreenHeader("\tUpdate Currency Rate");

        string CurrencyCode = "";
        cout << "\nPlease Enter currency code: ";
        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency Code is not found, Enter another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

        _PrintCurrency(Currency);

        cout << "\nAre you sure you want to update this currency y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\n\nUpdate Currency Rate:";
            cout << "\n____________________\n";

            float NewRate;

            Currency.UpdateRate(_ReadCurrencyRate());

            cout << "\nCurrency Rate Updated Successfully :-)\n\n";
            _PrintCurrency(Currency);
        }
    }

};

