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

	string np;
	getline(input, np);

	vector<Friend> friends;
	for (int i = 0; i < stoi(np); i++)
	{
		string currentName;
		getline(input, currentName);
		friends.push_back(Friend(currentName));
	}

	string giver;
	while (getline(input, giver))
	{
		string line;
		getline(input, line);
		int spaceLocation = line.find_first_of(' ');
		string totalMoney = line.substr(0, spaceLocation);
		string numberOfPersons = line.substr(spaceLocation+1, line.length() - spaceLocation+1); //TODO VERIFY THIS
		int giftedMoney = stoi(totalMoney);
		int nPersons = stoi(numberOfPersons);
		int moneyFraction = nPersons == 0 ? 0 : giftedMoney / nPersons;
		int remainderMoney = nPersons == 0 ? 0 : giftedMoney % nPersons;

		for (int i = 0; i < friends.size(); i++)
		{
			if (friends.at(i).getName() == giver)
				friends.at(i).updateBalance(-giftedMoney + remainderMoney);
		}

		for (int j = 0; j < nPersons; j++)
		{
			string receiver;
			getline(input, receiver);
			for (int i = 0; i < friends.size(); i++)
			{
				if (friends.at(i).getName() == receiver)
					friends.at(i).updateBalance(moneyFraction);
			}
		}
	}

	//OUTPUT
	for (int i = 0; i < friends.size(); i++)
	{
		output << friends.at(i).getName() << ' ' << friends.at(i).getBalance() << '\n';
	}
	output.close();
}