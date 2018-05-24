#include <iostream>
using namespace std;

int prime[1000];

int main()
{
	for (int i = 2; i < 1000; i++)
		prime[i] = 1;

	for (int i = 2; i < 1000; i++)
	{
		if (prime[i] != 0)
		{
			prime[i] = i;

			int j = 2;
			while (i*j <= 1000)
			{
				prime[i*j] = 0;
				j++;
			}
		}
		continue;
	}

	int n,num,Count=0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (prime[num] != 0)
			Count++;
	}

	cout << Count << endl;
	return 0;
}