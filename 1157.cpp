#include <iostream>
#include <string>
using namespace std;

int main()
{
	int abc[26] = { 0 };
	string str;
	int high1 = 0, st;

	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] > 96)
			abc[str[i] - 97]++;

		else
			abc[str[i] - 65]++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (high1 < abc[i])
		{
			high1 = abc[i];
			st = i;
		}
	}

	for (int i = st+1; i < 26; i++)
	{
		if ((high1 == abc[i]))
		{
			cout << "?" << endl;
			return 0;
		}
	}

	cout << char(st + 65) << endl;

	return 0;
}