#include <cstdio>

int main()
{
	int n, sum = 0;
	int i,j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%1d", &j);
		sum = sum + j;
	}

	printf("%d\n", sum);
}