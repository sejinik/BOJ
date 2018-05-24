#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	
	for (int i = 0; i <N-1; i++)
	{
			for (int j = N -1; j > i; j--)
			{
				cout << " ";
			}
			for (int j = 0; j < 2 * i + 1; j++)
			{
				cout << "*";
			}
			cout << endl;
	}

	for (int i = N; i > 0; i--)
	{
		for (int j = 0; j < N - i; j++)
		{
			cout << " ";
		}
		
		for (int j = 2 * i - 1; j > 0; j--)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}