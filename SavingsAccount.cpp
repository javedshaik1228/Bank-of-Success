#include <iostream>
#include <string>
#include <ctime>
#include "SavingsAccount.h"
#include "CustomConsole.h"
#include "Dependencies.h"

using namespace std;

namespace BOS{
void SavingsAccount::setDOB(std::string dob){
    _dob=dob;
}
void SavingsAccount::setGender(Gender gender){
    _gender = gender;
}
void SavingsAccount::setNum(long phoneNum){
    _phoneNum=phoneNum;
}
std::string SavingsAccount::getDOB(){
  return _dob;
}
Gender SavingsAccount::getGender(){
    return _gender;
}
string SavingsAccount::getBuiltGender() {
	short gender = short(_gender);
	string res = "";
	switch(gender) {
		case 1: res = "Male";
			break;
		case 2: res = "Female";
			break;
		case 3: res = "Others";
			break;
		//default: res = "N/A";
	}
	return res;
}
long SavingsAccount::getNum(){
    return _phoneNum;
}

SavingsAccount::SavingsAccount(string dob) { //No need to call Parent class(Account) Parameterless constructor as compiler calls it automatically

	_dob = dob;
	short option;
	while(1) {
		cout << "1. Male" << endl;
		cout << "2. Female" << endl;
		cout << "3. Others" << endl; 
		cout << "Enter your Gender: ";
		option = CustomConsole::ReadShort();
		if(option <= 3 && option >= 1) break;
		else {
			cout << "Please Enter Valid Choice: ";
			continue;
		}
	}
	_gender = Gender(option);
	cout << "Enter Phone Number: ";
	_phoneNum = CustomConsole::ReadLong();
	
	/*Usually we call a setter which validates the data sent and then inputs the data into the data members. But we're not going over the top with such implementations now. We are just going to take inputs and initialize the data members directly */
}

SavingsAccount::~SavingsAccount() { } 
		
}
