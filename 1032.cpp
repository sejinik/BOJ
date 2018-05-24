#include <iostream>
#include <string>
using namespace std;


int main()
{
	string str, p_str = { 0 };
	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		str = { 0 };
		cin.ignore();
		cin >> str;
		if (i == 0)
			p_str = str;

		else 
		{
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] != p_str[i])
					p_str[i] = '?';
			}
		}
	}

	cout << p_str << endl;
	return 0;
}