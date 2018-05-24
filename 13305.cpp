#include <iostream>
#include <algorithm>
using namespace	 std;
#define ll long long
ll dist[100010];
ll sum[100010];
int n;

int main() {
	scanf("%d", &n);
	ll num = 0;
	for (int i = 0; i < n-1; i++) {
		scanf("%lld", &dist[i]);
		num += dist[i];
		sum[i] = num;
	}

	ll pay = 0;
	ll prev = 0;
	ll ans = 0;
	scanf("%lld", &prev);
	for (int i = 1; i < n; i++) {
		ll cost = 0;
		pay += dist[i - 1];
		scanf("%lld", &cost);
		if (cost < prev || i==n-1) {
			ans += (prev * pay);
			prev = cost;
			pay = 0;
		}
	}
	printf("%lld\n", ans);
	return 0;
}