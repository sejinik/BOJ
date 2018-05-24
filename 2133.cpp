#include <iostream>
#include <algorithm>
using namespace std;

int d[31];

int main()
{
	int num;
	scanf("%d", &num);

	d[2] = 3;
	for (int i = 4; i <= num; i++)
		if(i%2==0)
		for (int j = 2; j <= i; j=j + 2) {
			if (j == 2)
				d[i] += d[i - j] * 3;
			else if (j == i)
				d[i] += d[i - j] * 2 + 2;
			else
				d[i] += d[i - j] * 2;
		}

	
	int ans = d[num];
	printf("%d\n", ans);
	return 0;
}