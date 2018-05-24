#include <iostream>
using namespace std;

int main()
{
	int N, X;
	int array[10000];

	cin >> N >> X;

	for (int i = 0; i < N; i++)
	{
		cin >> array[i];
		if (array[i] < X)
			cout << array[i] << " ";
	}

	cout << endl;

	return 0;
}