#include "Users.h"

bool Users::_isAdult(const User* user)
{
	time_t seconds = time(NULL);
	tm* timeinfo = new tm;
	localtime_s(timeinfo, &seconds);

	bool res = false;

	if (user->getBirthday().getYear() < timeinfo->tm_year + 1900 - 18)
	{
		res = true;
	}

	else if (user->getBirthday().getYear() == timeinfo->tm_year + 1900 - 18)
	{
		if (user->getBirthday().getMonth() < timeinfo->tm_mon + 1)
		{
			res = true;
		}

		else if (user->getBirthday().getMonth() == timeinfo->tm_mon + 1 && user->getBirthday().getDay() <= timeinfo->tm_mday)
		{
			res = true;
		}
	}

	delete timeinfo;
	return res;
}

Users::Users(const std::string& path) :path{ path }
{
	this->load(path);
}

void Users::addUser(User* user)
{
	this->users.push_back(user);
}


bool Users::save(const std::string& path) const
{
	std::ofstream file(path);

	if(!file.is_open())
		return false;

	for (auto i : this->users)
	{
		file << *i << ", login: " << i->getLogin() << ", password: " << i->getPassword() << "\n";
	}
}

bool Users::load(const std::string& path)
{
	std::ifstream file(path);

	if (!file.is_open())
		return false;

	std::string str;

	while (std::getline(file, str))
	{
		std::string name, secName, surname;
		int b_day, b_month, b_year;
		int r_day, r_month, r_year;
		std::string login, pass;

		size_t i = str.find(' ');
		name = str.substr(0, i);
		str.erase(0, i + 1);

		i = str.find(' ');
		secName = str.substr(0, i);
		str.erase(0, i + 1);

		i = str.find(',');
		surname = str.substr(0, i);
		str.erase(0, i + 2);

		i = str.find(':', i + 1);
		str.erase(0, i + 2);

		b_day = std::stoi(str, &i);
		str.erase(0, i + 1);

		b_month = std::stoi(str, &i);
		str.erase(0, i + 1);

		b_year = std::stoi(str, &i);
		str.erase(0, i + 1);

		i = str.find(':', i + 1);
		str.erase(0, i + 2);

		r_day = std::stoi(str, &i);
		str.erase(0, i + 1);

		r_month = std::stoi(str, &i);
		str.erase(0, i + 1);

		r_year = std::stoi(str, &i);
		str.erase(0, i + 1);

		i = str.find(':');
		str.erase(0, i + 2);

		i = str.find(',');
		login = str.substr(0, i);
		str.erase(0, i + 2);

		i = str.find(':');
		pass = str.substr(0, i);
		str.erase(0, i + 2);

		pass = str;

		this->addUser(new User(FullName(name, secName, surname), Date(b_day, b_month, b_year), Date(r_day, r_month, r_year), login, pass));

	}

}

void Users::print() const
{
	for (auto i : this->users)
	{
		std::cout << *i << "\n";
	}
}

int Users::countOfShortNames(int length) const
{
	return std::count_if(begin(this->users), end(this->users), [length](User* user) { return user->getName().length() < length; });
}

int Users::countOfAdults() const
{
	return std::count_if(begin(this->users), end(this->users), this->_isAdult);
}

Users::~Users()
{
	this->save(path);
}
