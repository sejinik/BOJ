#include <iostream>
using namespace std;

int num[9];

int main()
{
	int sum = 0;

	for (int i = 0; i < 9; i++)
	{
		cin >> num[i];
		sum += num[i];
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - num[i] - num[j] == 100)
			{
				num[i] = 0;
				num[j] = 0;
				break;
			}
		}
		if (num[i] == 0)
			break;
	}
		
	for (int i = 0; i < 9; i++)
		if (num[i] != 0)
			cout << num[i] << endl;
	return 0;

}