#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	unsigned long long a, b,MIN,MAX;

	scanf("%llu %llu", &a, &b);

	if (a == b)
	{
		printf("0\n");
		return 0;
	}

	MIN = min(a, b);
	MAX = max(a, b);

	printf("%llu\n", MAX - MIN - 1);

	for (unsigned long long i = MIN; i < MAX - 1; i++)
		printf("%llu ", i + 1);
	

	return 0;
}