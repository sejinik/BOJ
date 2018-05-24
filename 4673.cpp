#include <iostream>
using namespace std;

int selfnumber(int n)
{
	if (n >= 1000)
		return n + n / 1000 + (n % 1000) / 100 + (n % 100) / 10 + n % 10;

	else if (n >= 100)
		return n + n / 100 + (n % 100) / 10 + n % 10;

	else if (n >= 10)
		return n + n / 10 + n % 10;

	else
		return n + n;
}

int arr[10001];

int main()
{
	int res;

	for (int i = 0; i < 10001; i++)
	{
			res = selfnumber(i);
			arr[res] = -1;
			
			if (arr[i] != -1)
			{
				arr[i] = i;
				cout << arr[i] << endl;
			}
	}



	return 0;
}