#include <unordered_map>
#include <string>
#include "Account.h"


namespace BOS{
    class AccountManager{
        private:
            std::unordered_map<long id, Account* acc>;
            std::string transferLog;
            AccountManager* _instance;
            AccountManager(){
                //empty
            }
        public:
            static AccountManager* getInstance();
            void printTransferLog();
            void printMenu();
            void openAccount();

    };


}