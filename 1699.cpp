#include <iostream>
#include <algorithm>
using namespace std;

int d[100001];

int main()
{
	int num;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++)
		d[i] = i;
	
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j*j <= i; j++) {
			d[i] = min(d[i],d[i - j*j]+ 1);
		}
	}

	int ans = d[num];
	printf("%d\n", ans);
	return 0;
}