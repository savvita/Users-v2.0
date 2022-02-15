#pragma once
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include"User.h"

class Users
{
private:
	std::vector<User*> users;
	std::string path;

	static bool _isAdult(const User* user);

public:
	explicit Users(const std::string& path); 

	void addUser(User* user);

	bool save(const std::string& path) const;
	bool load (const std::string& path);

	void print() const;

	int countOfShortNames(int length) const;

	int countOfAdults() const;

	~Users();
};

