#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int len = 2 * N - 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i + 1; j++)
			cout << "*";
		for (int j = len-2*i-1; j > 0; j--)
			cout << " ";
		for (int j = 0; j < i + 1; j++)
			cout << "*";
		cout << endl;
	}

	for (int i = 0; i < len - N; i++)
	{
		for (int j = len-N-i ; j > 0; j--)
			cout << "*";
		for (int j = 0; j < 2 * i+2; j++)
			cout << " ";
		for (int j = len-N-i ; j > 0; j--)
			cout << "*";
		cout << endl;
	}

}