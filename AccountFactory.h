#pragma once

#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"

namespace BOS{

    class AccountFactory{
    	    static IAccount* createSavingsAccount();
    	    static IAccount* createCurrentAccount();
    	    static AccountFactory* _instance;
            AccountFactory(){
                //empty
            }
        public:
            static IAccount* createAccount(int type);
            ~AccountFactory();
    };

}
