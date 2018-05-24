#include <iostream>
using namespace std;

int arr[100][100];


int main()
{
	int Tcase1,sum=0,x,y;
	cin >> Tcase1;

	for (int i = 0; i < Tcase1; i++)
	{
		cin >> x >> y;
		for (int i = x; i < x + 10; i++)
			for (int j = y; j < y + 10; j++)
				arr[i][j] = 1;
			
	}

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			sum = sum + arr[i][j];

	cout << sum << endl;
	return 0;
	
}