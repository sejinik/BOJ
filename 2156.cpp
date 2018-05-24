#include <iostream>
#include <algorithm>	
using namespace std;

long long d[10001][3];
long long a[10001];

int main()
{
	int N;
	scanf("%d", &N);

	int num;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &num);
		a[i] = num;
	}

	d[1][0] = 0;
	d[1][1] = a[1];
	d[1][2] = 0;

	for (int i = 2; i <= N; i++) {
		d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
		d[i][1] = d[i - 1][0] + a[i];
		d[i][2] = d[i - 1][1] + a[i];
	}

	long long ans;
	ans = max(d[N][0], max(d[N][1], d[N][2]));
	printf("%lld\n", ans);
	return 0;
}