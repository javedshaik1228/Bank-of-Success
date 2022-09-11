#include <string>
#include "Account.h"
#include "Dependencies.h"

namespace BOS{
    class SavingsAccount: public Account{
        private:
            std::string _dob;
            Gender _gender;
            long _phoneNum;
        public:
            //implement getters and setters
            SavingsAccount();
            ~SavingsAccount();
            void setDOB(std::string dob);
            void setGender(char gender);
            void setNum(long phoneNum);
            std::string getDOB();
            char getGender();
            long getNum();
    };
}
