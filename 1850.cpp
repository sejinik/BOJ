#include <iostream>
using namespace std;

long long GCD(long long x, long long y)
{
	if (y == 0)
		return x;
	else
		return GCD(y, x%y);
}

int main()
{
	long long a, b,g;
	cin >> a >> b;
	g = GCD(a, b);
	
	for (int i = 0; i < g; i++)
		cout << 1;
	cout << endl;
	return 0;
	
}