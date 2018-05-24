#include <iostream>
#include <string.h>
using namespace std;

int main()
{

	int abc[26];

	for (int i = 0; i < 26; i++)
	{
		abc[i] = -1;
	}

	char str[101] = { 0 };

	cin.getline(str, sizeof(str));

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == str[i - 1])
			continue;
		
		if(abc[(int)str[i] - 97] == -1)
		abc[(int)str[i] - 97] = i;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << abc[i] << " ";
	}

	cout << endl;

	return 0;
}