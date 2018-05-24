#include <iostream>
using namespace std;

int min(int x, int y)
{
	return x > y ? y : x;
}

int max(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	int x, y,big=1,small,a,b;
	cin >> x >> y;
	a = min(x, y); // 둘중 작은수
	b = max(x, y); // 둘중 큰수

	if (x == 1)
		cout << a << endl << b << endl;

	else if (x == y)
		cout << x << endl << y << endl;

	else
	{
		for (int i = 2; i <= a; i++)
		{
			if (a%i == 0 && b%i == 0)
				big = i; // 최대공약수
			
		}
		
		for (int i = 1; i <= b; i++)
		{
			if (((a*i) % b) == 0)
			{
				small = a*i; // 최소공배수
				break;
			}
		}
		cout << big << endl << small << endl;
	}
	return 0;
	

}