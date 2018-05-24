#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n, k, coupon, chicken;

	while ((scanf("%d %d", &n, &k)) != -1)
	{
		coupon = n;
		chicken = n;
		while (coupon >=k)
		{
			chicken = chicken + coupon / k;
			coupon = coupon / k + coupon%k;
		}
		printf("%d\n", chicken);
	}
	return 0;
}