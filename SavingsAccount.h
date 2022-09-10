#include <string>
#include "Account.h"

namespace BOS{
    class SavingsAccount: public Account{
        private:
            std::string _dob;
            char _gender;
            long _phoneNum;
        public:
            //implement getters and setters
            void setDOB(std::string dob);
            void setGender(char gender);
            void setNum(long phoneNum);
            std::string getDOB();
            char getGender();
            long getNum();
    };
}