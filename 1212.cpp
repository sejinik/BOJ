#include <iostream>
#include <string>
using namespace std;


int main()
{
	string str;
	int bin[8] = { 0,1,10,11,100,101,110,111 };
	int res[10000] = { 0 };

	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		res[i] = str[i]-48;
		if (i != 0)
		{
			if (res[i] == 0 || res[i] == 1)
				cout << "00";
			else if (res[i] == 2 || res[i] == 3)
				cout << "0";
		}
		cout << bin[res[i]];
	}
	cout << endl;

	return 0;

}