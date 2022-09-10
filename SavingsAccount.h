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
    };
}