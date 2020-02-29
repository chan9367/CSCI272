#include "Account.h"
#include "Savings.h"
#include "Checking.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {

  Savings mySav{"John Doe", 100.00, .05};
  Account *acctPtr = &mySav;
  mySav.deposit(300);
  mySav.withdraw(100);

  acctPtr->accountStatement();

  Savings *savPtr = &mySav;
  savPtr->accountStatement();

  Checking myChk{"John Doe", 500};
  acctPtr = &myChk;
  myChk.deposit(800);
  myChk.withdraw(100);

  acctPtr->accountStatement();
  Checking* chkPtr = &myChk;
  chkPtr->accountStatement();
  
/*
  vector<Account*> accounts;

  Savings* sav1 = new Savings{"John Doe", 345.75, .04};
  accounts.push_back(sav1);
  Savings* sav2 = new Savings{"Jane Doe", 891.45, .05};
  accounts.push_back(sav2);
  Checking* chk1 = new Checking{"Jane Doe", 567.23};
  accounts.push_back(chk1);
  Checking* chk2 = new Checking{"John Doe", 398.12};
  chk2->issue_debit_card();
  accounts.push_back(chk2);
  Checking* chk3 = new Checking{"John Doe", 123.54};
  accounts.push_back(chk3);

  for (int i = 0; i < accounts.size(); i++){
    accounts[i]->accountStatement();
  }
  */
/*
  for (int i = 0; i < accounts.size(); i++){
    accounts[i]->accountInfo();
  }

*/
}