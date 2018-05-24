#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int Tcase;
	int x, y,res;

	cin >> Tcase;

	for (int i = 0; i < Tcase; i++)
	{
		cin >> x >> y;

		if (x%10 == 1 || x%10 == 5 || x%10 == 6)
			cout << x%10 << endl;

		else if (x%10 == 2 || x%10 == 3 || x%10 == 7 || x%10 == 8)
		{
			if (y % 4 != 0)
			{
				res = pow(x%10, y % 4);
				cout << res % 10 << endl;
			}
			else
			{
				res = pow(x%10, 4);
				cout << res % 10 << endl;
			}
		}

		else if (x%10 == 0)
			cout << 10 << endl;

		else
		{
			if (y % 2 != 0)
				cout << x%10 << endl;
			else
			{
				res = pow(x%10, 2);
				cout << res % 10 << endl;
			}
		}
	}
	return 0;
}