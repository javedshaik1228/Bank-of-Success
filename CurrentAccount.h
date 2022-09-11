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
            CurrentAccount();
            ~CurrentAccount();
            void setCompanyName(std::string companyName);
            void setWebsite(std::string website);
            void setRegno(long regNo);
            std::string getCompanyName();
            std::string getWebsite();
            long getRegno();
    };
}
