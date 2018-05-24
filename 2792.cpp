#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll n,arr[300030];
int m;
bool go(ll mid) {
	ll ret = 0;
	for (int i = 0; i < m; i++) {
		ret += arr[i] / mid;
		if (arr[i] % mid != 0) ret += 1;
	}
	return ret <= n;
}
int main() {
	scanf(" %lld %d", &n, &m);
	for (int i = 0; i < m; i++) scanf(" %lld", &arr[i]);
	ll left = 1, right = 1e18, ans = 1e18;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (go(mid)) {
			ans = min(ans, mid);
			right = mid - 1;
		}
		else left = mid + 1;
	}
	printf("%lld\n", ans);
}