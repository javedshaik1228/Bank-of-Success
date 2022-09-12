#pragma once

#include <iostream>
#include <map>
#include <string>
#include "Account.h"

using namespace std;

namespace BOS{
    class AccountManager{
        private:
            map<long, Account*> _accounts;
            string _transferLog;
            
        public:
            static AccountManager* getInstance();
            void printTransferLog();
            //void printMenu();
            void openAccount(Account* account);
            ~AccountManager();
    };


}
