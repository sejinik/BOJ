#include <iostream>
using namespace std;

int main()
{

	int x;
	int sum = 0;
	int i = 1;

	cin >> x;
	
	while (true)
	{
		sum = sum + i;
		
		if (x <= sum)
			break;

		i++;
	}
	
	if (i % 2 == 1)
	{
		cout << sum - x + 1 << "/" << x - sum + i << endl;
	}

	else
	{
		cout << x - sum + i << "/" << sum - x + 1 << endl;
	}


	return 0;

}