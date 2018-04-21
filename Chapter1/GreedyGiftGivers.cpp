/*
ID: up201701
TASK: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Friend
{
public:
	Friend(string name);
	string getName();
	int getBalance();
	void updateBalance(int);
private:
	string name;
	int balance = 0;
};

Friend::Friend(string name)
{
	this->name = name;
}

string Friend::getName()
{
	return name;
}

int Friend::getBalance()
{
	return balance;
}

void Friend::updateBalance(int money)
{
	balance += money;
}

int main()
{
	ifstream input("gift1.in");
	ofstream output("gift1.out");

	int np;
	input >> np;
	input.ignore(1000, '\n');

	vector<Friend> friends;
	for (int i = 0; i < np; i++)
	{
		string currentName;
		getline(input, currentName);
		friends.push_back(Friend(currentName));
	}

	string line;
	while (getline(input, line))
	{
		int spaceLocation = line.find_first_of(' ');
		string totalMoney = line.substr(0, spaceLocation);
		string numberOfPersons = line.substr(spaceLocation, line.length() - spaceLocation); //TODO VERIFY THIS

	}
	


}