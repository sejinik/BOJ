#include <iostream>
using namespace std;

int main()
{
	int N;
	int arr[46] = { 0,1 };
	cin >> N;
	for (int i = 2; i <= 45; i++)
	{
		arr[i] = arr[i - 2] + arr[i - 1];
	}

	cout << arr[N] << endl;
	return 0;
}