#include <iostream>
using namespace std;

int main()
{
	int x, y;
	int high = 0;
	int sum = 0;
	int train[4] = {0};

	for (int i = 0; i < 4; i++)
	{
		cin >> x >> y;
		sum = sum + y - x;
		train[i] = sum;

		if (high < train[i])
			high = train[i];
	}

	cout << high << endl;
	return 0;
}