#include <iostream>
using namespace std;

int main()
{
	int T, a, b;
	char c;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> a >> c >> b;
		cout << a + b << endl;
	}
	return 0;
}