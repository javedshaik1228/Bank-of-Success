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
	AccountManager accManager;
	
	//AccountFactory Singleton Instance
	AccountFactory* accFactory = AccountFactory::createFactoryInstance();
	
	
	



	return 0;
}
