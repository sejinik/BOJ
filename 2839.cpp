#include <iostream>
using namespace std;

int main()
{
	int N;

	cin >> N;

	int Z = (N - ((N / 5) * 5));
	int Count = N / 5;

	if (N == 7)
	{
		cout << "-1" << endl;
		return 0;
	}

	if (N % 5 == 0)
	{
		cout << Count << endl;
		return 0;
	}

	while (Z %3 != 0)
	{			
		Z = Z + 5;
		Count--;

		if (Z == N)
			break;

		if (Z > N)
		{
			cout << "-1" << endl;
			return 0;
		}
	}

	cout << Z / 3 + Count << endl;
	return 0;
}