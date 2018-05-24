#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll inf = 1e+11;
ll n, m;
ll arr[100010];

int main() {
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}

	ll left = 0;
	ll right = 0;
	ll sum = arr[0];
	ll ans = inf;

	while (left <= right && right < n) {
		if (sum == m) {
			ll cnt = right - left + 1;
			ans = min(ans, cnt);

			right += 1;
			sum += arr[right];
		}
		else if (sum < m) {
			right += 1;
			sum += arr[right];
		}
		else {
			ll cnt = right - left + 1;
			ans = min(ans, cnt);
			sum -= arr[left];
			left += 1;
		}
	}
	if (ans == inf) puts("0");
	else printf("%lld\n", ans);
	return 0;
}