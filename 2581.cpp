#include <iostream>
using namespace std;

int prime[10001];

int main()
{
	for (int i = 2; i <= 10000; i++)
		prime[i] = 1;

	for (int i = 2; i <= 10000; i++)
	{
		if (prime[i] != 0)
		{
			prime[i] = i;

			int j = 2;
			while (i*j <= 10000)
			{
				prime[i*j] = 0;
				j++;
			}
		}
		continue;
	}

	int m, n, sum = 0;

	cin >> m >> n;

	for (int i = m; i <= n; i++)
	{
		if (prime[i] != 0)
			sum = sum + prime[i];
	}

	if (sum == 0)
		sum = -1;

	cout << sum << endl;
	int i = m;
	while (1)
	{
		if (sum == -1)
			return 0;

		else if (prime[i] != 0)
		{
			cout << prime[i] << endl;
			return 0;
		}
		i++;
	}
}