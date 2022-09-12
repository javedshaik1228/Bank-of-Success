#pragma once

#include <string>
#include "Account.h"
#include "Dependencies.h"

namespace BOS{
    class SavingsAccount: public Account{
        private:
            std::string _dob;
            Gender _gender;
            long _phoneNum;
            SavingsAccount();
        public:
            //implement getters and setters
            SavingsAccount(string dob);
            ~SavingsAccount();
            void setDOB(std::string dob);
            void setGender(Gender gender);
            void setNum(long phoneNum);
            std::string getDOB();
            Gender getGender();
            string getBuiltGender();
            long getNum();
    };
}
