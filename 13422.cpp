#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
int main() {
	ll t; scanf(" %lld", &t);
	while (t--) {
		ll n, m, k; scanf(" %lld %lld %lld", &n, &m, &k);
		m--;
		ll ans = 0;
		vector<ll> arr(n,0);
		vector<ll> sum(n*2,0);
		for (int i = 0; i < n; i++) {
			scanf(" %lld", &arr[i]);
			if (i == 0) sum[i] = arr[i];
			else sum[i] = sum[i - 1] + arr[i];
		}
		for (int i = n; i < n * 2; i++) sum[i] = sum[i - 1] + arr[i - n];
		if (sum[m] < k) ans++;
		if (n != (m+1)) {
			for (int i = 1; i < n; i++) {
				if (sum[i + m] - sum[i - 1] < k) ans++;
			}
		}
		printf("%lld\n", ans);
	}
}