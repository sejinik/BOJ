#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll n, m;
ll arr[100010];
bool go(ll mid) {
	ll cnt = 0;
	for (ll i = 0; i < n; i++) cnt += (mid / (ll)arr[i]);
	if (cnt >= m) return true;
	return false;
}
int main() {
	scanf("%lld %lld", &n, &m);
	for (ll i = 0; i < n; i++) scanf(" %lld", &arr[i]);
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