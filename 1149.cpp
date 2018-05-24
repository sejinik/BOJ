#include <iostream>
#include <algorithm>
using namespace std;

long long d[1001][3];
long long a[1001][3];

int main()
{
	int N;
	scanf("%d",&N);

	for(int i=1;i<=N;i++)
		for (int j = 0; j < 3; j++) {
			int pri;
			scanf("%d", &pri);
			a[i][j] = pri;
		}

	d[1][0] = a[1][0];
	d[1][1] = a[1][1];
	d[1][2] = a[1][2];

	for (int i = 2; i <= N; i++) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + a[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + a[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + a[i][2];
	}

	long long ans;
	ans = min(d[N][0], min(d[N][1], d[N][2]));
	printf("%lld\n", ans);
	return 0;
}