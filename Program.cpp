#include <iostream>
#include "IAccount.h"
#include "AccountManager.h"
#include "Account.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"
#include "CustomConsole.h"
#include "AccountFactory.h"

using namespace std;
using namespace BOS;

int main() {
	//Account Manager Instance
	AccountManager* accManager = AccountManager::getInstance();
	
	//AccountFactory 
	while(1){
		accManager->printMenu();
		cout<<"Do you want to continue: y/n ";
		if(CustomConsole::ReadChar() == 'y')
			continue;
		else
			break;
	}
	
	
	



	return 0;
}
