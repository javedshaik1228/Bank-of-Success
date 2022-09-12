#include "CustomConsole.h"
#include "Account.h"
#include "AccountFactory.h"
#include "AccountManager.h"

using namespace std;

namespace BOS {

	AccountManager* AccountManager::_instance;
	
	AccountManager::AccountManager(){
		//empty
	}

	AccountManager* AccountManager::getInstance(){
		if(AccountManager::_instance == NULL){
			_instance = new AccountManager();
		}
		return _instance;
	}
		
	void AccountManager::printTransferLog() {
		cout << _transferLog << endl;
	}
	
	//to be revisited
	void AccountManager::openAccount() {
		cout<<"Enter which type of Account you want to open: "<<endl;
		cout<<"1. Savings Account \n2. Current Account: "<<endl;
		
		IAccount* iacc = AccountFactory::createAccount(CustomConsole::ReadInt());
		if(iacc == nullptr){
			return;
		}
		Account* acc = dynamic_cast<Account*> (iacc); //downcast to access setters and getters
		cout << "Enter Name: ";
		acc->setName(CustomConsole::ReadString());
		cout << "Enter Custom PIN(four digits): ";
		acc->setPin(CustomConsole::ReadString());
		while(acc->getPin().size() != 4) {
			cout << "Please enter a four digit pin: ";
			acc->setPin(CustomConsole::ReadString());
		}

		cout << "Enter today's Date(dd/mm/yyyy): ";
		acc->setActivationDate(CustomConsole::ReadString());

		cout<<"Account Created successfully! Your Account number is: "<<acc->getAccNumber()<<endl;

		_accounts.insert(std::pair<long, IAccount*> (acc->getAccNumber(), iacc));

		
	}
	
	AccountManager::~AccountManager() {}

	void AccountManager::accountReport(){
		AccountReport::DisplayAccounts(_accounts);
	}

	void AccountManager::printMenu(){
		std::cout<<"---------------------------- Account Manager Menu ----------------------------"<<std::endl;
		std::cout<<" 1. Open Account \n 2. Close Account \n 3. Withdraw \n 4. Deposit \n 5. Display Accounts"<<std::endl;

		switch(CustomConsole::ReadInt()){
			case 1:		//openAccount   
				openAccount();
				break;
			case 2:		//closeAccount
				std::cout<<"Enter the account number for the account you want to close: "<<std::endl;
				long accClose;
				accClose = CustomConsole::ReadLong();
				if(_accounts.find(accClose) != _accounts.end()){
					_accounts[accClose]->closeAccount();
				}	
				else{
					cout<<"Invalid Account Number!"<<endl;
				}
				break;
			case 3:		//withdraw
				std::cout<<"Enter the account number for the account you want to withdraw from: "<<std::endl;
				long accNo;
				accNo = CustomConsole::ReadLong();
				if(_accounts.find(accNo) != _accounts.end()){
					std::cout<<"Enter the amount you want to withdraw: "<<endl;
					_accounts[accNo]->withdraw(CustomConsole::ReadDouble());
				}
				else{
					cout<<"Invalid Account Number!"<<endl;
				}
				break;
			case 4:		//deposit
				std::cout<<"Enter the account number for the account you want to deposit into: "<<std::endl;
				long accNo_dep;
				accNo_dep = CustomConsole::ReadLong();
				if(_accounts.find(accNo_dep) != _accounts.end()){
					std::cout<<"Enter the amount you want to deposit: "<<endl;
					_accounts[accNo_dep]->deposit(CustomConsole::ReadDouble());
					cout<<"Amount deposited succesfully!"<<endl;
				}
				else{
					cout<<"Invalid Account Number!"<<endl;
				}
				break;
			case 5:		//report
				accountReport();
				break;
			default:
				std::cout<<"Invalid Choice! "<<std::endl;
				break;
		}
	}


}