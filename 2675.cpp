#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int Tcase;
	int r;
	int rarr[1000] = { 0 };
	char s[1000][21];
	cin >> Tcase;

	for (int i = 0; i < Tcase; i++)
	{
		cin >> r >> s[i];
		rarr[i] = r;
	}

	for (int i = 0; i < Tcase; i++)
	{
		for (int j = 0; j < strlen(s[i]); j++)
		{
			for (int k = 0; k < rarr[i];k++)
			{
				cout << s[i][j];
			}
		}
		cout << endl;
	}

	return 0;
}