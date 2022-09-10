#include <unorderd_map>
#include <string>
#include "IAccount.h"

namespace BOS{

    class Account : public IAccount{
        private:
            long _accNumber;
            std::string _name;
            std::string _pin;
            double _balance;
            bool _isActive;
            std::string _activationDate;
            std::string _closingDate;
            std::unorderd_map< std::string date, std::vector<double> > transfersToday; //first = date of Trans, second = vector of trans made in that day
        public:
            Account();
            virtual ~Account();
            //implement getters and setters

    };


}