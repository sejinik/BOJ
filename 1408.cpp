#include <iostream>
using namespace std;

int main()
{
	
	char a;
	int A[6], B[6],i=0;
	while (cin >> a)
	{
		if (a != ':')
		{
			A[i] = a-48;
			i++;
		}
		if (i == 6)
			break;
	}

	i = 0;
	while (cin >> a)
	{
		if (a != ':')
		{
			B[i] = a - 48;
			i++;
		}
		if (i == 6)
			break;
	}

	for (int i = 0; i < 6; i = i + 2)
	{
		A[i] = A[i] * 10 + A[i + 1];
		B[i] = B[i] * 10 + B[i + 1];
	}

	for (int i = 4; i >= 0; i = i - 2)
	{
		B[i] = B[i] - A[i];
		if (B[i] < 0 && i != 0)
		{
			B[i] = B[i] + 60;
			B[i - 2]--;
		}

		else if (B[i] < 0 && i == 0)
			B[i] = B[i] + 24;
	}

	for (int i = 0; i <= 4; i++)
	{
	
		if (i % 2 == 0)
		{
			if (B[i] >= 10)
				cout << B[i];
			else
				cout << "0" << B[i];
		}
		
		else
		cout << ":";
	}
	cout << endl;
	return 0;
}	
