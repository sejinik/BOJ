#include <iostream>
using namespace std;

int num[5];

int main()
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> num[i];
		sum = sum + num[i];
	}

	int temp;
	for(int i=0;i<4;i++)
		for (int j = i + 1; j < 5; j++)
			if (num[i] > num[j])
			{
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
	
	cout << sum / 5 << endl << num[2] << endl;

	return 0;
}