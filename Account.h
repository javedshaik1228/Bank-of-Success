#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <vector>
#include "IAccount.h"
#include "Dependencies.h"

using namespace std;

namespace BOS{

    class Account: public IAccount {
        protected:
            static long _autoAccNo;
            long _accNumber;
            std::string _name;
            std::string _pin;
            double _balance;
            PrivilegeType _privilege;
            bool _isActive;
            string _activationDate;
            string _closingDate;
            map<string, vector<double>> _transfersToday; //first = date of Trans, second = vector of trans made in that day
        public:
            Account();
            virtual ~Account();
            //implement getters and setters
            void setAccNumber(long accNumber);
            void setName(std::string name);
            void setPin(std::string pin);
            void setBalance(double balance);
            void setPrivilege(short privelege);
            void setIsActive(bool isActive);
            void setActivationDate(std::string activationDate);
            void setClosingDate(std::string closingDate);
            void setTransferToday(std::string date,double transfers);
            long getAccNumber();
            std::string getName();
            std::string getPin();
            double getBalance();
            short getPrivilege();
            string getBuiltPrivilege();
            bool getIsActive();
            std::string getActivationDate();
            std::string getClosingDate();
            virtual void closeAccount();
            virtual bool withdraw(double amt);
            virtual bool deposit(double amt);
            virtual bool checkActive();
    };


}
