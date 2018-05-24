#include <iostream>
using namespace std;

int d[1010];

int main()
{
	int num;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		if (i == 1)
			d[i] = 1;
		else if (i == 2)
			d[i] = 2;
		else
			d[i] = (d[i - 1] + d[i - 2])%10007;
	}
	printf("%d\n", d[num]);
	return 0;
}