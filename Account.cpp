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

void Account::setPrivelege(short privelege) {
	_privelege = PrivelegeType(privelege);
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
void Account::setTransferToday(std::string date,double transfers){
    _transfersToday[date].push_back(transfers);
}
long Account::getAccNumber(){
    return _accNumber;
}
std::string Account::getName(){
    return _name;
}
std::string Account::getPin(){
    return _pin;
}
double Account::getBalance(){
    return _balance;
}
short Account::getPrivelege() {
	return short(_privelege);
}
string Account::getBuiltPrivelege() {
	short option = getPrivelege();
	swtich(option) {
		case 1: return "PREMIUM";
			break;
		case 2: return "GOLD";
			break;
		case 3: return "SILVER";
			break;
		default: return "INVALID";
	}
}

bool Account::getIsActive(){
    return _isActive;
}
std::string Account::getActivationDate(){
    return _activationDate;
}
std::string Account::getClosingDate(){
     return _closingDate;
}
std::unordered_map< std::string , std::vector<double> > Account::getTransferToday(){
    return _transfersToday;
}
void Account::closeAccount(){
    Account::setIsActive(0);
    cout << "Enter today's Date(dd/mm/yyyy): ";
    setClosingDate(CustomConsole::ReadString());
}

bool Account::withdraw(double amt){
    if(Account::getIsActive()){
        if((Account::getBalance()-amt)>=0){
            Account::setBalance(Account::getBalance()-amt);
            
            return true;
        }
        else{
            return false;
        }
    }

   return false; 
}
bool Account::deposit(double amt){
    if(Account::getIsActive()){
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
	cout << "Enter Name: ";
	_name = CustomConsole::ReadString();
	cout << "Enter Custom PIN(four digits): ";
	_pin = CustomConsole::ReadString();
	while(_pin.size() != 4) {
		cout << "Please enter a four digit pin: ";
		_pin = CustomConsole::ReadString();
	}
	_balance = 0;
	short option;
	while(1) {
		cout << "1. PREMIUM" << endl;
		cout << "2. GOLD" << endl;
		cout << "3. SILVER" << endl;
		cout << "Please select a privelege type: ";
		option = CustomConsole::ReadInt();
		if(option <= 3 && option >= 1) break;
		else {
		cout << "Please enter a valid choice" << endl;
		}
	}
	_privelege = PrivelegeType(option);
	_isActive = 1;
	_cout << "Enter today's Date(dd/mm/yyyy): ";
	_activationDate = CustomConsole::ReadString();
	
	/*Usually we call a setter which validates the data sent and then inputs the data into the data members. But we're not going over the top with such implementations now. We are just going to take inputs and initialize the data members directly */
}

Account::~Account() {}
}
