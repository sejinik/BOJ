#include <iostream>
#include <string>
using namespace std;

string gan = "6789012345";
string ji = "IJKLABCDEFGH";


int main()
{
	int year;

	cin >> year;
	year = year % 60;

	gan = gan[year % 10];
	ji = ji[year % 12];
	cout << ji << gan << endl;

	return 0;
}