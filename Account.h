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
            //setters
            void setAccNumber(long accNumber);
            void setName(std::string name);
            void setPin(std::string pin);
            void setBalance(double balance);
            void setPrivilege(short privelege);
            void setIsActive(bool isActive);
            void setActivationDate(std::string activationDate);
            void setClosingDate(std::string closingDate);
            void setTransferToday(std::string date,double transfers);

            //getters
            long getAccNumber() const;
            std::string getName() const;
            std::string getPin() const;
            double getBalance() const;
            short getPrivilege() const;
            string getBuiltPrivilege() ;
            bool getIsActive() const;
            std::string getActivationDate() const;
            std::string getClosingDate() const;

            //member functions
            virtual void closeAccount();
            virtual bool withdraw(double amt);
            virtual bool deposit(double amt);
            virtual bool checkActive();
            virtual bool checkPin(std::string pin);

    };


}
