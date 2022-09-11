#include "SavingsAccount.h"

namespace BOS{
void SavingsAccount::setDOB(std::string dob){
    _dob=dob;
}
void SavingsAccount::setGender(char gender){
    _gender=gender;
}
void SavingsAccount::setNum(long phoneNum){
    _phoneNum=phoneNum;
}
std::string SavingsAccount::getDOB(){
  return _dob;
}
char SavingsAccount::getGender(){
    return _gender;
}
long SavingsAccount::getNum(){
    return _phoneNum;
}

}