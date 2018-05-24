#include <iostream>
#include <string>
using namespace std;

int main()
{
	int Tcase, res;
	string str;

	while (1)
	{
		cin >> Tcase;

		if (Tcase == 0)
			return 0;

		res = 0;
		cin.ignore(1,'\n');

		for (int i = 0; i < Tcase; i++)
		{
			getline(cin, str);
			for (int j = res; j < str.length(); j++)
			{
				if (str[j] == ' ')
				{
					res = j;
					break;
				}
				else if (j == str.length() - 1)
				{
					res = str.size();
					break;
				}
			}
		}
		cout << res + 1 << endl;
	}
	return 0;
}