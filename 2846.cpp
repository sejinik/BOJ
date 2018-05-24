#include <iostream>
using namespace std;

int num[1010];

int main()
{
	int n, score=0,high=0,Count=0;
	cin >> n>>num[0];

	
	for (int i = 1; i < n; i++)
	{
		cin >> num[i];

		if (num[i - 1] >= num[i])
		{	
			Count++;
			score = 0;
		}
		else
			score = score + num[i] - num[i - 1];

		if (score > high)
			high = score;
		
	}

	if (Count == n - 1)
		cout << 0 << endl;
	else
		cout << high << endl;
	return 0;
	
}