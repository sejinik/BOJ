#include <iostream>
#include <string>
using namespace std;

int num[10];

int main()
{
	string str;
	int highN = 0, num_6=0,num_9=0,print;

	cin >> str;

	for (int i = 0; i < str.length(); i++)
		num[str[i] - '0']++;
	
	for (int i = 0; i < 10; i++)
	{
		if (i == 6)
			num_6 = num[i];

		else if (i == 9)
			num_9 = num[i];
		
		else
			if (num[i] >= highN)
				highN = num[i];
	}

	if (highN>= num_6 && highN>= num_9)
		cout << highN << endl;

	else
	{
		if ((num_6 + num_9) % 2 == 0)
			cout << (num_6 + num_9) / 2 << endl;

		else
			cout << (num_6 + num_9) / 2 + 1 << endl;
		
	}
	return 0;
}

