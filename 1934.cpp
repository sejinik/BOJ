#include <iostream>
#include <cstdio>
using namespace std;

int GCD(int x, int y)
{
	if (y == 0)
		return x;
	else
		return GCD(y, x%y);
}

int main()
{
	int Tcase,x,y,gcd;
	scanf("%d", &Tcase);
	
	while (Tcase--)
	{
		scanf("%d%d", &x, &y);
		gcd = GCD(x, y);
		printf("%d\n", x*y / gcd);
	}
	return 0;
}