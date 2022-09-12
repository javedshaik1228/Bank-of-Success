#include "AccountReport.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"

namespace BOS{
    void AccountReport::PrintLine()
    {
        cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    }

    void AccountReport::DisplayHeader()
    {
        PrintLine();
        cout << "ACCOUNTS REPORT" << endl;
        PrintLine();
    }

    void AccountReport::DisplayFooter(int count)
    {
        PrintLine();
        cout << "Total Accounts : "<< count << endl;
        PrintLine();
    }

    void AccountReport::DisplayAccounts(map<long, IAccount*> accounts)
    {
        AccountReport::DisplayHeader();

        cout << "S.NO\tACC_NUMBER\tNAME\tACCOUNT TYPE\tACTIVATION DATE\t\tBALANCE\t\tIS ACTIVE\tCLOSING DATE" << endl;

        int count = accounts.size();
        int i = 1;
        for (auto iacc = accounts.begin(); iacc != accounts.end(); iacc++){

            Account* acc = dynamic_cast<Account *>(iacc->second);
            cout<<i++<<". "<<"\t";
            cout<<iacc->first<<"\t\t";
            cout<<acc->getName()<<"\t";

            SavingsAccount *sav= dynamic_cast<SavingsAccount *>(acc);
            if(sav != NULL){
                cout<<"Savings\t\t";
            }
            else{
                CurrentAccount *curr= dynamic_cast<CurrentAccount *>(acc);
                if(curr != NULL){
                    cout<<"Current\t\t";
                }
            }
            cout<<acc->getActivationDate()<<"\t\t";
            cout<<acc->getBalance()<<"\t\t";

            if(acc->getIsActive()){
                cout<<"YES\t";
                cout<<"NA\t";
            }
            else{
                cout<<"NO\t";
                cout<<acc->getClosingDate()<<"\t";
            }

            cout<<endl;
        }
        AccountReport::DisplayFooter(count);
    }


}