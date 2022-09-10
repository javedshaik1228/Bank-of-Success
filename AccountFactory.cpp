#include "AccountFactory.h"

namespace BOS{

    Account* AccountFactory::createAccount(){
        Account* acc;
        int choice = 0;
        std::cout<<"Enter the type of Account you want to create: \n 1. Savings \n 2. Current"<<std::endl;
        std::cin>>choice;

        switch(choice){
            case 1:
                acc = new SavingsAccount();
                return acc;
            case 2:
                acc = new CurrentAccount();
                return acc;
            default:
                std::cout<<"Invalid Choice!"<<std::endl;
                break;
        }
        return AccountFactory::createAccount(); //enter again


    }
}