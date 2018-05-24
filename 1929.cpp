#include <iostream>
using namespace std;

int pArry[1000001];

int main()
{
	for (int i = 2; i < 1000001; i++)
	{
		pArry[i] = 1;
	}
	
	int n, m;
	cin >> n >> m;
	pArry[0] = 0;
	pArry[1] = 0;

	for (int i = 2; i <= 1000000; i++)
	{
		if (pArry[i] != 0)
		{
			pArry[i] = i;
			int j = 2;
			while (i*j <= 1000000)
			{
				pArry[i*j] = 0;
				j++;
			}
		}
		else if (pArry[i] == 0)
			continue;
	}

	for (int i = n; i <= m; i++)
	{
		if (pArry[i] != 0)
			cout << pArry[i] << endl;
	}


	return 0;

}