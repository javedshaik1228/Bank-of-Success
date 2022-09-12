#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "IAccount.h"
#include "Account.h"
#include "AccountReport.h"

using namespace std;

namespace BOS{
    class AccountManager{
        private:
            map<long, IAccount*> _accounts;
            string _transferLog;
            AccountManager();
            static AccountManager* _instance;
            
        public:
            static AccountManager* getInstance();
            void printTransferLog();
            void printMenu();
            void openAccount();
            void accountReport();
            ~AccountManager();
    };


}
