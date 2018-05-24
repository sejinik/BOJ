#include <iostream>
using namespace std;

int main()
{
	int N,i;
	int sum = 1;
	cin >> N;

	for (i = 0;; i++)
	{
		sum = sum + (6 * i);
		if (sum >= N)
			break;
	}

	cout << i + 1 << endl;

}