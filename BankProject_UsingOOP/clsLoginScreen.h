#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{
private:
    static  bool _Login()
    {
        bool LoginFaild = false;
        string Username, Password;
        short FailedLoginCounter = 0;
        do
        {
             if (LoginFaild)
             {
                 FailedLoginCounter++;
             cout << "\nInvlaid Username/Password!\n";
             cout << "You have " << 3-FailedLoginCounter << " trial(s) to login...\n\n";
             }
             if (FailedLoginCounter == 3)
             {
                 cout << "You are locked after 3 failed trials!\n";
                 return false;
             }
             cout << "Enter Username? ";
             cin >> Username;

             cout << "Enter Password? ";
             cin >> Password;

             CurrentUser = clsUser::Find(Username, Password);

             LoginFaild = CurrentUser.IsEmpty();
        } while (LoginFaild);
        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:
    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();
    }
};