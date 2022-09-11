#include "Account.h"
namespace BOS{
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
std::string Account::setPin(){
    return _pin;
}
double Account::getBalance(){
    return _balance;
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

}