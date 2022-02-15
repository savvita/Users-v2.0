#include<algorithm>
#include<vector>
#include"Users.h"

using namespace std;
bool isAdult(const User* user);

int main()
{
	//vector<User*> users;

	//users.push_back(new User(FullName("Ivan", "Ivanovich", "Ivanov"), Date(16, 2, 2004), Date(15, 02, 2022), "", ""));
	//users.push_back(new User(FullName("Vladislav", "Ivanovich", "Ivanov"), Date(12, 5, 2012), Date(15, 02, 2022), "", ""));
	//users.push_back(new User(FullName("Ivan", "Ivanovich", "Ivanov"), Date(12, 5, 1980), Date(15, 02, 2022), "", ""));
	//users.push_back(new User(FullName("Svyatoslav", "Ivanovich", "Ivanov"), Date(12, 5, 2012), Date(15, 02, 2022), "", ""));
	//users.push_back(new User(FullName("Ivan", "Ivanovich", "Ivanov"), Date(12, 5, 1941), Date(15, 02, 2022), "", ""));

	//std::cout << "Short names: " << count_if(begin(users), end(users), [](User* user) { return user->getName().length() < 7; }) << "\n";
	//std::cout << "Born at 2012: " << count_if(begin(users), end(users), [](User* user) { return user->getBirthday().getYear() == 2012; }) << "\n";
	//std::cout << "Adults: " << count_if(begin(users), end(users), isAdult) << "\n";

	Users users("22.txt");
	//users.addUser(new User(FullName("Ivan", "Ivanovich", "Ivanov"), Date(16, 2, 2004), Date(15, 02, 2022), "dgh", "123"));
	//users.addUser(new User(FullName("Vladislav", "Ivanovich", "Ivanov"), Date(12, 5, 2012), Date(15, 02, 2022), "", ""));
	//users.addUser(new User(FullName("Ivan", "Ivanovich", "Ivanov"), Date(12, 5, 1980), Date(15, 02, 2022), "kjhlk", "qwerty"));
	//users.addUser(new User(FullName("Svyatoslav", "Ivanovich", "Ivanov"), Date(12, 5, 2012), Date(15, 02, 2022), "", ""));
	//users.addUser(new User(FullName("Ivan", "Ivanovich", "Ivanov"), Date(12, 5, 1941), Date(15, 02, 2022), "", ""));

	users.print();

	std::cout << "Names sorter than 7: " << users.countOfShortNames(7) << "\n";
	std::cout << "Adults: " << users.countOfAdults() << "\n";

}

bool isAdult(const User* user)
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
