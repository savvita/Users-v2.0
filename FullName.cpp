#include "FullName.h"

FullName::FullName(const std::string& name, const std::string& secondName, const std::string& surname) : name{ name }, secondName{ secondName }, surname{ surname }
{
}

const std::string& FullName::getName() const
{
	return this->name;
}

const std::string& FullName::getSecondName() const
{
	return this->secondName;
}

const std::string& FullName::getSurname() const
{
	return this->surname;
}

std::ostream& operator<<(std::ostream& out, const FullName& fName)
{
	out << fName.name << " " << fName.secondName << " " << fName.surname;
	return out;
}
