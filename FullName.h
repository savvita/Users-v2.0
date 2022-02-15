#pragma once
#include<iostream>
#include<string>

class FullName
{
private:
	std::string name;
	std::string secondName;
	std::string surname;

public:
	FullName(const std::string& name, const std::string& secondName, const std::string& surname);

	//gets
	const std::string& getName() const;
	const std::string& getSecondName() const;
	const std::string& getSurname() const;

	friend std::ostream& operator<<(std::ostream& out, const FullName& fName);
};

