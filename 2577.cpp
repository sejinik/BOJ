#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	int arr[10] = { 0 };
	int arr2[10] = { 0 };
	int res;
	cin >> a >> b >> c;

	res = a*b*c;
	
	arr2[0] = res;
	int Count = 0;
	int i = 1;
	
	while (1)
	{
		if (res == 0)
			break;

		res = res / 10;
		arr2[i] = res;
		i++;
		Count++;
	}

	for (int i = 0; i < Count; i++)
	{
		arr2[i] = arr2[i] % 10;
		arr[arr2[i]]++;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	return 0;


}