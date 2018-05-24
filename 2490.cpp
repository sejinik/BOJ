#include <iostream>
using namespace std;

int main()
{
	int n = 3, sum;
	int arr[4];
	char res[5] = { 'D','C','B','A','E' };

	while (n != 0)
	{
		sum = 0;
		for (int i = 0; i < 4; i++)
		{
			cin >> arr[i];
			sum = sum + arr[i];
		}
		cout << res[sum] << endl;
		n--;
	}
	return 0;
}