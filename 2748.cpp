#include <iostream>
using namespace std;


int main()
{
	unsigned long long arr[91] = { 0,1 };

	for (int i = 2; i <= 90; i++)
	{
		arr[i] = arr[i - 2] + arr[i - 1];

	}
	
	int N;
	cin >> N;
	cout << arr[N] << endl;

	return 0;
}