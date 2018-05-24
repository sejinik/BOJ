#include <iostream>
using namespace std;

int prime[10001];

int main()
{
	for (int i = 2; i < 10001; i++)
	{
		prime[i] = 1;
	}

	for (int i = 2; i < 10001; i++)
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
	}
	
	int Tcase,num,res;
	cin >> Tcase;

	for (int i = 0; i < Tcase; i++)
	{
		cin >> num;

		for (int i = num; i>=num/2; i--)
		{
			if (prime[i] != 0 && prime[num-i] != 0)
			{
				
				res = i;
			}
		}
		cout << num - res << " " << res << endl;
	}
	

	return 0;
	
	
}