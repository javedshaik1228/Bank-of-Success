#include <string>
#include "Account.h"

namespace BOS{
    class CurrentAccount: public Account{
        private:
            std::string _companyName;
            std::string _website;
            long _regNo;
        public:
            //implement getters and setters
    };
}