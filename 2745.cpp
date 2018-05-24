#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	string str;
	int N, sum=0,num;
	cin >> str >> N;
	reverse(str.begin(), str.end());

	for (int i = 0; i < str.length(); i++)
	{
		num = 0;

		if (str[i] >= 'A')
			num = (int)(str[i] - 'A' + 10);
		else
			num = (str[i]-'0');

		sum = sum + num * pow(N, i);
	}
	cout << sum << endl;
	return 0;
}