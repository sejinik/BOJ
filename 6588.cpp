#include <iostream>
#include <cstdio>
using namespace std;

int prime[999999];

int main()
{
	prime[0] = 1;
	prime[1] = 1;

	for (int i = 2; i<999999; i++)
	{
		if (prime[i] != 1)
		{
			prime[i] = i;

			int j = 2;
			while (i*j < 999999)
			{
				prime[i*j] = 1;
				j++;
			}
		}
	}

	while (1)
	{
		int n=0, print = 0;
		scanf("%d", &n);

		if (n == 0)
			return 0;

		for (int i = 2; i <= n / 2 + 1; i++)
		{
			if ((prime[i] != 1) && (prime[n - prime[i]] != 1))
			{
				print = i;
				break;
			}
		}
		printf("%d = %d + %d\n", n, print, n - print);
	}

	return 0;
}