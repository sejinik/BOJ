#include <iostream>
using namespace std;

int Count;

void han(int n)
{
	if (n >= 100)
	{
		if ((n / 100 - (n % 100) / 10) == ((n % 100) / 10 - n % 10))
			Count++;
	}

	else
		Count++;
}

int main()
{
	int num;
	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		han(i);
	}
	cout << Count << endl;
	return 0;
}