#include "Date.h"

Date::Date(int day, int month, int year) :day{ day }, month{ month }, year{ year }
{
}

int Date::getDay() const
{
	return this->day;
}

int Date::getMonth() const
{
	return this->month;
}

int Date::getYear() const
{
	return this->year;
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	out << date.day << "." << date.month << "." << date.year;
	return out;
}
