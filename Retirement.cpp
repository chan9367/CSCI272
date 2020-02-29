#include "Retirement.h"
#include <iostream>

Retirement::Retirement(std::string name, double start_bal, std::string aret_type):Account(name,start_bal){ret_type=aret_type;} // name, balance, ret_type
void Retirement::accountStatement() const{
  if(ret_type=="r"){std::cout << "\nROTH ACCOUNT STATEMENT\n=======================\n" << getName();}
  else if(ret_type=="t"){std::cout << "\nTRADITIONAL IRA ACCOUNT STATEMENT\n=======================\n" << getName();}
  else {std::cout << "\nRETIREMENT ACCOUNT STATEMENT\n=======================\n" << getName();}
  for (int i = 0; i < transactions.size(); i++){
    if (transactions[i] > 0){
      std::cout << "\nDeposit ";
    }
    else{
      std::cout << "\nWithdrawal ";
    }
    std::cout << transactions[i];
  }
}
void Retirement::accountInfo() const{
  if(get_ret_type()=="r")std::cout<<"\nRetirement Type: ROTH";
  else if(get_ret_type()=="t")std::cout<<"\nRetirement type: TRADITIONAL IRA";
  std::cout << "\nAccount name: " << getName();
  std::cout << "\tBalance: $" << getBalance();
}
std::string Retirement::get_ret_type() const{return ret_type;}
