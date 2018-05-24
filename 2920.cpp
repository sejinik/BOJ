#include <iostream>
using namespace std;

int main()
{
	
	int arr[8];
	int as = 0;
	int des = 8;

	for (int i = 0; i < 8; i++)
	{
		cin >> arr[i];
		if (arr[i] == i+1)
		{
			as++;
		}
		else if (arr[i] == 8 - i)
		{
			des--;
		}
	}

	if (as == 8)
		cout << "ascending" << endl;

	else if (des == 0)
		cout << "descending" << endl;

	else
		cout << "mixed" << endl;

	return 0;
}