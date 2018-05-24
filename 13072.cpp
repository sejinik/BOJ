#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
int n, k;
ll arr[10010];

ll go(ll mid) {
	ll cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += arr[i] / mid;
	}
	return cnt;
}
int main() {
	scanf("%d %d", &n, &k);
	
	ll left = 1;
	ll right = 0;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
		right = max(right, arr[i]);
	}

	while (left <= right) {
		ll mid = (left + right) / 2;
		if (go(mid) >= k) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	printf("%lld\n", ans);
	return 0;
}