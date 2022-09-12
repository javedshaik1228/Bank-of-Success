#include <iostream>
#include <map>
#include <vector>
#include "AccountManager.h"
#include "Account.h"

using namespace std;

namespace BOS {
		
	void AccountManager::printTransferLog() {
		cout << _transferLog << endl;
	}
	
	void AccountManager::openAccount(Account* account) {
		if(account != nullptr) 
			_accounts.insert({account->getAccNumber(), account});
	}
	
	AccountManager::~AccountManager() {}
}
