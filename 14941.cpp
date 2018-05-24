#include <iostream>
#include <algorithm>
using namespace std;
bool check[100010];
int prime[10000];
int prime_cnt;

void Find_Prime() {
	for (int i = 2; i <= 100000; i++) {
		if (!check[i]) {
			prime[prime_cnt++] = i;
			for (int j = i * 2; j <= 100000; j += i)
				check[j] = true;
		}
	}
}


int main() {
	Find_Prime();
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		int c = lower_bound(prime, prime + prime_cnt, a) - prime;
		int d = lower_bound(prime, prime + prime_cnt, b) - prime;

		int ans = 0;
		int cnt = 0;
		for (int j = c; j <= d; j++) {
			if (j == d && prime[j] > b) continue;
			if (cnt % 2 == 0) ans += prime[j] * 3;
			else ans -= prime[j];
			cnt += 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}