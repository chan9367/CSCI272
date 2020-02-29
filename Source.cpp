#include <string>
#include <sstream>
#include <iostream>
#include "Time.h"
#include "Date.h"
using namespace std;

void displayTime(const Time* time) {
	cout << "\n24 hour clock: " << time->to24hourformat();
	cout << "\nAM/PM format: " << time->toAMPMformat() << endl;

}

void printDate(const Date* date){
	cout << "\nString Date: " << date->toString();
	cout << "\nFull Display Date: " << date->fullDisplay();
}
int main() {
	/*
	Time time1;
	Time time2{12};
	Time time3{22,30};
	Time time4{ 7,45,30 };
	
	displayTime(&time1); displayTime(&time2); displayTime(&time3); displayTime(&time4);

	string usertime;
	cout << "\nEnter time: h:m:s\n";
	getline(cin, usertime);

	istringstream inputtime{ usertime };
	int hour, minute, second;
	char colon;

	inputtime >> hour >> colon >> minute >> colon >> second;
	Time newtime{ hour, minute, second };
	displayTime(&newtime);
	*/


	//Lab 3

	Date date1;
	Date date2{ 12 };
	Date date3{ 9,3 };
	Date date4{ 2,8,2019 };
	Date invalid{ 345,123,549182 };

	printDate(&date1); printDate(&date2); printDate(&date3); printDate(&date4);

	string userdate;
	cout << "\Enter Date MM/DD/YYYY: ";
	getline(cin, userdate);

	istringstream inputdate{ userdate };
	int month, day, year;
	char slash;

	inputdate >> month >> slash >> day >> slash >> year;
	Date newdate{ month, day, year };
	printDate(&newdate);



	system("pause");
}