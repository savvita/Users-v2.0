#include "User.h"

User::User(const FullName& fName, const Date& birthday, const Date& registration, const std::string& login, const std::string& password):
	fName{ fName }, birthday{ birthday }, registration{ registration }, login{ login }, password{ password }
{
}

const std::string& User::getName() const
{
	return this->fName.getName();
}

const std::string& User::getSecondName() const
{
	return this->fName.getSecondName();
}

const std::string& User::getSurname() const
{
	return this->fName.getSurname();
}

const Date& User::getBirthday() const
{
	return this->birthday;
}

const Date& User::getRegistration() const
{
	return this->registration;
}

const std::string& User::getLogin() const
{
	return this->login;
}

const std::string& User::getPassword() const
{
	return this->password;
}

std::ostream& operator<<(std::ostream& out, const User& user)
{
	out << user.fName << ", birthday: " << user.birthday << ", registration: " << user.registration;

	return out;
}
