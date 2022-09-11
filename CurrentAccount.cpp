#include <iostream>
#include "CurrentAccount.h"
#include "CustomConsole.h"

using namespace std;
namespace BOS{
    void CurrentAccount::setCompanyName(std::string companyName){
        _companyName=companyName;
    }
    void CurrentAccount::setWebsite(std::string website){
        _website=website;
    }
    void CurrentAccount::setRegno(long regNo){
        _regNo=regNo;
    }
    std::string CurrentAccount::getCompanyName(){
        return _companyName;
    }
    std::string CurrentAccount::getWebsite(){
        return _website;
    }
    long CurrentAccount::getRegno(){
        return _regNo;
    }
    
    CurrentAccount::CurrentAccount() { //No need to call Parent class(Account) Parameterless constructor as compiler calls it automatically
    	cout << "Enter Company Name: ";
    	_companyName = CustomConsole::ReadString();
    	cout << "Enter Company Website: ";
    	_website = CustomConsole::ReadString();
    	cout << "Enter Company Registration Number: ";
    	_regNo = CustomConsole::ReadLong();
    	
    	/*Usually we call a setter which validates the data sent and then inputs the data into the data members. But we're not going over the top with such implementations now. We are just going to take inputs and initialize the data members directly */
}
