#include <iostream>
#include <ctime>
#include <string>
#include "AccountFactory.h"
#include "Account.h"
#include "CustomConsole.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"

using namespace std;

namespace BOS{

    IAccount* AccountFactory::createSavingsAccount() {
    	IAccount* acc;
		cout << "Enter DOB(dd/mm/yyyy): ";
		string dob = CustomConsole::ReadString();
		
		//calculating year

		time_t time = std::time(nullptr);
		tm* now = localtime(&time);
		int curr_year = (now->tm_year + 1900);
		int dob_year = stoi(dob.substr(6, 4));
			
		if((curr_year - dob_year) < 18) {
			cout << "Age is less than 18!" << endl;
			cout << "Cannot process Account creation!" << endl;
			acc = nullptr;
			return acc;
		}
			else {
					acc = new SavingsAccount(dob);
					return acc;
			}    	
	}
		
	IAccount* AccountFactory::createCurrentAccount() {
		IAccount* acc;
		cout << "Enter Company Registration Number: ";
		long regNo = CustomConsole::ReadLong();
		if(regNo) {
				acc = new CurrentAccount(regNo);
				return acc;
		}
		else {
				cout << "Company Registration Number cannot be null!" << endl;
				cout << "Cannot process Account creation!" << endl;
				acc = nullptr;
				return acc;
		}
	}

    IAccount* AccountFactory::createAccount(int choice){

        switch(choice){
            case 1:
            	return createSavingsAccount();
                break;
            case 2:
                return createCurrentAccount();
                break;
            default:
                std::cout<<"Invalid Choice!"<<std::endl;
        }
        
        return AccountFactory::createAccount(choice);
    }

	AccountFactory::~AccountFactory(){
			//empty
	}

}
