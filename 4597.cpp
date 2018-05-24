#include <iostream>
#include <string>
using namespace std;

int main()
{

	string st1;
	
	while (1)
	{
		cin >> st1;
		if (st1 == "#")
			return 0;

		int sum = 0;

		for (int i = 0; i < st1.length(); i++)
			if (st1[i] == '1')
				sum++;
		
		if (sum % 2 == 0)
		{
			if (st1[st1.length() - 1] == 'e')
				st1[st1.length() - 1] = '0';
			else
				st1[st1.length() - 1] = '1';
		}
		else
		{
			if (st1[st1.length() - 1] == 'e')
				st1[st1.length() - 1] = '1';
			else
				st1[st1.length() - 1] = '0';
		}
		cout << st1 << endl;
	}
	return 0;
}