#include <iostream>
#include <algorithm>
using namespace std;

int d[1010];
int p[1010];

int main()
{
	int num, price;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++)
		scanf("%d", &p[i]);

	for(int i=1;i<=num;i++)
		for (int j = 1; j <= i; j++) {
			d[i] = max(d[i],p[j] + d[i - j]);
		}
	printf("%d\n", d[num]);
	return 0;
}