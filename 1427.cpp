#include <iostream>
#include <string>
using namespace std;

int main()
{	
	string str;
	int temp;
	cin >> str;

	for (int i = 0; i < str.size()-1; i++)
	{
		for (int j = i + 1; j < str.size(); j++)
		{
			if (str[i] < str[j])
			{
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}

	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i];
	}
	cout << endl;

	return 0;

}