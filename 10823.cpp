#include <iostream>
#include <string>
using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif // _CONSOLE

	string st1, st2="";
	int sum = 0 , num = 0;

	while (cin >> st1)
		st2 += st1;

	for (int i = 0; i < st2.length(); i++)
	{
		if (st2[i] != ',')
			num = num * 10 + (int)(st2[i] - '0');

		else 
		{
			sum = sum + num;
			num = 0;
		}
	}
	sum += num;
	cout << sum << endl;
	return 0;
}

