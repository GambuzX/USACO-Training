/*
ID: up201701
LANG: C++
TASK: friday
*/
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

bool isLeapYear(const int &year)
{
	if (year % 100 == 0) //if century year
		return year % 400 == 0; //divisible by 400
	return year % 4 == 0;
}

int nDays(const int &month, const int &year)
{
	int n = 0;
	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		n = 31;
		break;
	case 4: case 6: case 9: case 11:
		n = 30;
		break;
	case 2:
		isLeapYear(year) ? n = 29 : n = 28;
		break;
	}
	return n;
}

int main()
{
	ifstream istream("friday.in");
	ofstream ostream("friday.out");

	//int day = 1, month = 1, year = 1900, weekday = 1;
	int weekday = 1, n;
	map<int, int> mm;
	istream >> n;

	for (int year = 1900; year < 1900 + n; year++)
	{
		for (int month = 1; month <= 12; month++)
		{
			int days = nDays(month, year);
			for (int day = 1; day <= days; day++)
			{
				if (day == 13)
				{
					mm[weekday]++;
				}
				weekday == 7 ? weekday = 1 : weekday++;
			}
		}
	}

	ostream << mm[6] << ' ';
	ostream << mm[7] << ' ';
	ostream << mm[1] << ' ';
	ostream << mm[2] << ' ';
	ostream << mm[3] << ' ';
	ostream << mm[4] << ' ';
	ostream << mm[5] << '\n';

	ostream.close();
	istream.close();

	return 0;
}