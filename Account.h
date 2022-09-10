#pragma once

#include <unordered_map>
#include <string>
#include <vector>
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
            std::unordered_map< std::string , std::vector<double> > _transfersToday; //first = date of Trans, second = vector of trans made in that day
        public:
            Account();
            virtual ~Account();
            //implement getters and setters
            void setAccNumber(long accNumber);
            void setName(std::string name);
            void setPin(std::string pin);
            void setBalance(double balance);
            void setIsActive(bool isActive);
            void setActivationDate(std::string activationDate);
            void setClosingDate(std::string closingDate);
            void setTransferToday(std::string date,double transfers);
            long getAccNumber();
            std::string getName();
            std::string setPin();
            double getBalance();
            bool getIsActive();
            std::string getActivationDate();
            std::string getClosingDate();
            std::unordered_map< std::string , std::vector<double> > getTransferToday();
            virtual void closeAccount();
            virtual bool withdraw(double amt);
            virtual bool deposit(double amt);
            virtual bool checkActive();
    };


}