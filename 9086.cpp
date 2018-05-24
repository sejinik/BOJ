#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int Tcase;
	cin >> Tcase;

	for (int i = 0; i < Tcase; i++)
	{
		cin >> str;
		if (str.length() == 1)
			cout << str << str << endl;
		else
			cout << str[0] << str[str.length()-1] << endl;
	}
	return 0;
}