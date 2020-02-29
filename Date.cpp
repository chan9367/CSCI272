#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "Date.h"

Date::Date(int month, int day, int year) {
	setDate(month, day, year);
}

void Date::setDate(int m, int d, int y) {
	setMonth(m);
	setDay(d);
	setYear(y);
}
void Date::setMonth(int m) {
	if (month > 0 && m < 13)
	{
		month = m;
	}
	else {
		std::cout << "\nInvalid month: " << m << std::endl;
	}
}
void Date::setDay(int d) {
	if (day > 0 && d < 32)
	{
		day = d;
	}
	else {
		std::cout << "\nInvalid day: " << d << std::endl;
	}
}

void Date::setYear(int y) {
	if (year >= 0)
	{
		year = y;
	}
	else {
		std::cout << "\nInvalid year: " << y << std::endl;
	}
}

unsigned int Date::getMonth() const { return month; }
unsigned int Date::getDay() const { return day; }
unsigned int Date::getYear() const { return year; }

std::string Date::toString()const {
	std::ostringstream output;

	output << month << "/" << day << "/" << year << std::endl;

	return output.str();

}
std::string Date::fullDisplay() const {
	std::ostringstream output;

	output << std::setw(2) << 
			((month == 1) ? "January" 
			: (month == 2)? "February" 
			: (month == 3) ? "March" 
			: (month == 4) ? "April" 
			: (month == 5) ? "May"
			: (month == 6) ? "June"
			: (month == 7) ? "July"
			: (month == 8) ? "August"
			: (month == 9) ? "September"
			: (month == 10) ? "October"
			: (month == 11) ? "November"
			: "December")
		<< " " << std::setw(2) << day << ", " << std::setw(2) << year << std::endl;

	return output.str();
}