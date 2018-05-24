#include <iostream>
#include <string>	
using namespace std;

int num[100];

int main()
{
	string str;
	cin >> str;
	num[0] = str[0];

	for (int i = 1; i < str.length(); i++)
		if (str[i] == '-')
			num[i+1] = str[i + 1];
	
	for (int i = 0; i < str.length(); i++)
		if (num[i] != 0)
			cout << str[i];

	cout << endl;

	return 0;
}