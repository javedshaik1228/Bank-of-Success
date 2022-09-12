#pragma once

#include <string>
#include "Account.h"
#include "Dependencies.h"

namespace BOS{
    class SavingsAccount: public Account{
        private:
            std::string _dob;
            Gender _gender;
            std::string _phoneNum;
            SavingsAccount();
        public:
            //implement getters and setters
            SavingsAccount(string dob);
            ~SavingsAccount();
            void setDOB(std::string dob);
            void setGender(Gender gender);
            void setNum(std::string phoneNum);
            std::string getDOB();
            Gender getGender();
            string getBuiltGender();
            std::string getNum();
    };
}
