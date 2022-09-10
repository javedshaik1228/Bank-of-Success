#include <string>
#include "Account.h"

namespace BOS{
    class IAccount{
        public:
            //pure virtual funs, implementations to be done in child classes (Account, Savings, Current classes)
            virtual void closeAccount() = 0;
            virtual bool withdraw(double amt) = 0;  //doesnt need accNum as parameter since it is invoked by an acc object
            virtual bool deposit(double amt) = 0;
            virtual void transferFunds(long toAcc, double amt) = 0;
            virtual bool checkActive() = 0;
    };
}