#include <iostream>
#include "Account.h"
#include "CustomConsole.h"
#include "Dependencies.h"

using namespace std;

namespace BOS{
	long Account::_autoAccNo = 1000;

	void Account::setAccNumber(long accNumber){
		_accNumber=accNumber;
	}
	void Account::setName(std::string name){
		_name=name;
	}
	void Account::setPin(std::string pin){
		_pin=pin;
	}
	void Account::setBalance(double balance){
		_balance=balance;
	}

	void Account::setPrivilege(short privelege) {
		_privilege = PrivilegeType(privelege);
	}

	void Account::setIsActive(bool isActive){
		_isActive=isActive;
	}
	void Account::setActivationDate(std::string activationDate){
		_activationDate=activationDate;
	}
	void Account::setClosingDate(std::string closingDate){
		_closingDate=closingDate;
	}
	void Account::setTransferToday(std::string date, double transfers){
		_transfersToday[date].push_back(transfers);
	}
	long Account::getAccNumber() const{
		return _accNumber;
	}
	std::string Account::getName() const{
		return _name;
	}
	std::string Account::getPin() const{
		return _pin;
	}
	double Account::getBalance() const{
		return _balance;
	}
	short Account::getPrivilege() const{
		return short(_privilege);
	}
	string Account::getBuiltPrivilege() {
		short option = getPrivilege();
		string res = "";
		switch(option) {
			case 1: res = "PREMIUM";
				break;
			case 2: res = "GOLD";
				break;
			case 3: res =  "SILVER";
				break;
			default: res = "INVALID";
		}
		return res;
	}

	bool Account::getIsActive() const{
		return _isActive;
	}
	std::string Account::getActivationDate() const{
		return _activationDate;
	}
	std::string Account::getClosingDate() const{
		return _closingDate;
	}
	void Account::closeAccount() {
		_isActive = false;
		cout << "Enter today's Date(dd/mm/yyyy): ";
		_closingDate = CustomConsole::ReadString();
		cout<<"Your remaining balance of amount of "<<_balance<<" has been withdrawn. Updated account balance is 0"<<endl;
		_balance = 0;
		cout<<"Your account has been closed! Thank you for your journey with Lakshmi Bank"<<endl;
	}

	bool Account::withdraw(double amt) {
		if(Account::getIsActive()){
			
			std::cout<<"Enter your pin: ";
			if(!checkPin(CustomConsole::ReadString())){
				cout<<"Incorrect Pin!"<<endl;
				return false;
			}

			//pin is checked here

			if((Account::getBalance()-amt)>=0){
				Account::setBalance(Account::getBalance()-amt);
				cout<<"Amount withdrawn succesfully!"<<endl;
				return true;
			}
			else{
				std::cout<<"Insufficient Balance!"<<std::endl;
				return false;
			}
		}

		return false; 
	}
	bool Account::deposit(double amt){
		if(Account::getIsActive()){
			std::cout<<"Enter your pin: ";
			if(!checkPin(CustomConsole::ReadString())){
				cout<<"Incorrect Pin!"<<endl;
				return false;
			}
			//correct pin

			Account::setBalance(Account::getBalance()+amt);
			return true;
		}

		return false; 
	}
	bool Account::checkActive(){
		return Account::getIsActive();
	}

	Account::Account() {
		_accNumber = _autoAccNo++;

		_balance = 0;
		_isActive = true;
		
		/*Usually we call a setter which validates the data sent and then inputs the data into the data members. But we're not going over the top with such implementations now. We are just going to take inputs and initialize the data members directly */
	}

	Account::~Account() {}

	//Defining pure virtual functions of IAccount Interface

	bool Account::checkPin(std::string pin){
		return (pin == _pin);
	}	

}


