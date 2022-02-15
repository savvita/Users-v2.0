#pragma once
#include"FullName.h"
#include"Date.h"

class User
{
private:
	FullName fName;
	Date birthday;
	Date registration;
	std::string login;
	std::string password;

public:
	User(const FullName& fName, const Date& birthday, const Date& registration, const std::string& login, const std::string& password);

	//gets
	const std::string& getName() const;
	const std::string& getSecondName() const;
	const std::string& getSurname() const;

	const Date& getBirthday() const;
	const Date& getRegistration() const;

	const std::string& getLogin() const;
	const std::string& getPassword() const;

	friend std::ostream& operator<<(std::ostream& out, const User& user);
};

