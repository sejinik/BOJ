#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	int num[10] = { 0 };
	int sum = 0;
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		num[str[i] - 48]++;
		sum = sum + str[i] - 48;
	}

	if (num[0] == 0 || sum % 3 != 0)
	{
		printf("%d\n", -1);
		return 0;
	}
	
	for (int i = 9; i >= 0; i--)
		for (int j = num[i]; j > 0; j--)
			printf("%d", i);
	
	printf("\n");
	return 0;
}