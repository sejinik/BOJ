#include <iostream>
using namespace std;

int prime[300000];

int main()
{
	for (int i = 2; i <= 300000; i++)
		prime[i] = 1;

	for (int i = 2; i <= 300000; i++)
	{
		if (prime[i] != 0)
		{
			prime[i] = i;

			int j = 2;
			while (i*j <= 300000)
			{
				prime[i*j] = 0;
				j++;
			}
		}
		continue;
	}

	int num = 1;
	while (1)
	{
	

		int Count = 0;
		cin >> num;

		if (num == 0)
			return 0;

		for (int i = num+1; i <= 2 * num; i++)
		{
			if (prime[i] != 0)
				Count++;
		}
		cout << Count << endl;
	}

	return 0;
}