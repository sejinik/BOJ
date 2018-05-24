#include <cstdio>
#define MOD 1000000000
long long d[2000030];
bool check[2000030];

int main() {

	
	d[1000001] = 1;
	for (int i = 1000002; i <= 2000000; i++) {
		d[i] = (d[i - 1]%MOD + d[i - 2]%MOD)%MOD;
		check[i] = true;
	}

	d[999999] = 1;
	check[999999] = true;
	d[999998] = -1;

	for (int i = 999999; i >= 2; i--) {
		d[i - 2] = ((d[i]%MOD) - (d[i - 1]%MOD))%MOD;

		if (d[i - 2] > 0) {
			check[i - 2] = true;
		}

	}

	int n;
	scanf("%d", &n);
	if (n == 0) {
		puts("0");
		puts("0");
	}
	else if (n > 0) {
		puts("1");
		printf("%lld\n", d[n + 1000000]);
	}
	else {
		if (check[n + 1000000])
			puts("1");
		else
			puts("-1");

		if (d[n + 1000000] < 0)
			printf("%lld\n", -d[n + 1000000]);
		else if(d[n+1000000] >0)
			printf("%lld\n", d[n + 1000000]);
	}
	return 0;
}