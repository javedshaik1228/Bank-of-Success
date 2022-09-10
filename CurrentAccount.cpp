#include "CurrentAccount.h"

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
}