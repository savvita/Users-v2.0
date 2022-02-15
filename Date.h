#pragma once
#include<iostream>

class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date(int day, int month, int year);

	//gets
	int getDay() const;
	int getMonth() const;
	int getYear() const;

	friend std::ostream& operator<<(std::ostream& out, const Date& date);
};

