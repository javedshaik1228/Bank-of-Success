#pragma once

#include <iostream>
#include <map>
#include "Account.h"

namespace BOS{
    class AccountReport
        {
            private:
                static void PrintLine();
                static void DisplayHeader();
                static void DisplayFooter(int Count);
            public:
                static void DisplayAccounts(map<long, IAccount* > accounts);
        };
}