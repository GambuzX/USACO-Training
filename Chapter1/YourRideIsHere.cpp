/*
ID: up201701
TASK: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream input("ride.in");
	ofstream output("ride.out");

	string cometName, groupName;
	getline(input, cometName);
	getline(input, groupName);

	int cometProduct = 1;
	for (int i = 0; i < cometName.length(); i++)
	{
		cometProduct *= ((int)cometName.at(i) - (int) 'A' + 1);
	}

	int groupProduct = 1;
	for (int i = 0; i < groupName.length(); i++)
	{
		groupProduct *= ((int)groupName.at(i) - (int) 'A' + 1);
	}

	if (cometProduct % 47 == groupProduct % 47)
		output << "GO\n";
	else
		output << "STAY\n";
	output.close();

	return 0;
}