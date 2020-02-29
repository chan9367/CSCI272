#include <string>
#pragma once

class Date {
public:
	Date (int = 2, int = 5, int = 2019);

	void setDate(int, int, int);
	void setMonth(int);
	void setDay(int);
	void setYear(int);

	unsigned int getMonth() const;
	unsigned int getDay() const;
	unsigned int getYear() const;

	std::string toString()const;
	std::string fullDisplay() const;

private:
	unsigned int month{ 2 };
	unsigned int day{ 5 };
	unsigned int year{ 2019 };



};