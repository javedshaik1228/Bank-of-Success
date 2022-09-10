#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"

namespace BOS{

    class AccountFactory{
        public:
            static Account* createAccount();
    };

}