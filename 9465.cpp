#include <iostream>
#include <algorithm>
using namespace std;

long long d[100010][3];
long long a[100010][2];

int main()
{
	int T, n;
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &n);

		long long num;
		for(int i=0;i<2;i++)
			for (int j = 1; j <= n; j++) {
				scanf("%lld", &num);
				a[j][i] = num;
			}

		d[1][0] = 0;
		d[1][1] = a[1][1];
		d[1][2] = a[1][0];

		for(int i=2;i<=n;i++) {
					d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
					d[i][1] = max(d[i - 1][0], d[i - 1][2]) + a[i][1];
					d[i][2] = max(d[i - 1][0], d[i - 1][1]) + a[i][0];
			}
		
		long long sum=0;
		printf("%lld\n", max(d[n][0], max(d[n][1], d[n][2])));
	}
	return 0;

}