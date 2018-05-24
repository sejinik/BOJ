#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	int num;
	string str,abc;
	cin >> num;


	for (int i = 0; i < num; i++)
	{
		cin.ignore();

		getline(cin, str);
		cin >> abc;

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ')
				cout << " ";

			else
			cout << abc[str[i] - 'A'];
		}
		cout << endl;
	}
	return 0;

}