bank: Program.o Account.o AccountFactory.o AccountManager.o SavingsAccount.o CurrentAccount.o CustomConsole.o AccountReport.o
	g++ -o bank Program.o Account.o AccountFactory.o AccountManager.o SavingsAccount.o CurrentAccount.o CustomConsole.o AccountReport.o

Program.o: Program.cpp Account.h AccountFactory.h AccountManager.h SavingsAccount.h CurrentAccount.h CustomConsole.h IAccount.h Dependencies.h
	g++ -c Program.cpp

Account.o: Account.cpp Account.h CustomConsole.h Dependencies.h
	g++ -c Account.cpp

AccountReport.o: AccountReport.cpp AccountReport.h
	g++ -c AccountReport.cpp

AccountFactory.o: AccountFactory.cpp AccountFactory.h Account.h CustomConsole.h SavingsAccount.h CurrentAccount.h
	g++ -c AccountFactory.cpp

AccountManager.o: AccountManager.cpp AccountManager.h Account.h
	g++ -c AccountManager.cpp

CurrentAccount.o: CurrentAccount.cpp CurrentAccount.h CustomConsole.h 
	g++ -c CurrentAccount.cpp

SavingsAccount.o: SavingsAccount.cpp SavingsAccount.h CustomConsole.h Dependencies.h
	g++ -c SavingsAccount.cpp

CustomConsole.o: CustomConsole.cpp CustomConsole.h
	g++ -c CustomConsole.cpp
