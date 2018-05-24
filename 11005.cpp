#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string str = "";
	int N, B;
	cin >> N >> B;

	while (N != 0)
	{
		int r = N%B;
		if (r < 10)
			str = str + (char)(r + '0');
		else
			str = str + (char)(r - 10 + 'A');
		N /= B;
	}

	reverse(str.begin(), str.end());
	cout << str << endl;
	return 0;
}