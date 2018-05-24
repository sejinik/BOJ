#include <iostream>
#include <string>
using namespace std;

int num[26];

int main()
{
	int Tcase;
	string str;

	cin >> Tcase;

	while (Tcase--)
	{	
		int sum = 0;
		
		for (int i = 0; i < 26; i++)
			num[i] = 0;
		cin >> str;

		for (int i = 0; i < str.length(); i++)
			num[int(str[i] - 'A')]++;
		
		for (int i = 0; i < 26; i++)
			if (num[i] == 0)
				sum = sum + (i + 65);

		cout << sum << endl;
		
	}
	return 0;
}