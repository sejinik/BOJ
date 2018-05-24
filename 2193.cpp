#include <iostream>
using namespace std;

unsigned long long d[91][2];

int main()
{
	int num;
	unsigned long long sum=0;
	scanf("%d",&num);

	d[1][0] = 0;
	d[1][1] = 1;

	for(int i=2;i<=num;i++)
		for (int j = 0; j < 2; j++) {
			if (j == 0)
				d[i][j] = d[i - 1][j + 1] + d[i - 1][j];
			else
				d[i][j] = d[i - 1][j - 1];
		}

	sum = d[num][0] + d[num][1];
	printf("%llu\n", sum);
	return 0;
}