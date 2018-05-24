#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int Count = 0;
	int Crolen = 0;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '=')
		{
			if (str[i - 1] == 'c' || str[i - 1] == 's')
			{
				Count++;
				Crolen = Crolen + 2;
			
			}
			else if (str[i - 1] == 'z')
			{
				Count++;

				if (str[i - 2] == 'd')
					Crolen = Crolen + 3;
				else
					Crolen = Crolen + 2;
			}
		}

		else if (str[i] == '-')
		{
			if (str[i - 1] == 'c' || str[i - 1] == 'd')
			{
				Count++;
				Crolen = Crolen + 2;
			}
		}

		else if (str[i] == 'j')
		{
			if (str[i - 1] == 'l' || str[i - 1] == 'n')
			{
				Count++;
				Crolen = Crolen + 2;
			}
		}
	}

	cout << str.size()+Count-Crolen<< endl;
	return 0;
}