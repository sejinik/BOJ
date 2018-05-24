#include <cstdio>

long long d[36];
int n;
int main() {
	scanf("%d", &n);
	d[0] = 1;
	d[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			d[i] += d[j] * d[i - 1 - j];
		}
	}
	printf("%lld\n", d[n]);
	return 0;
}