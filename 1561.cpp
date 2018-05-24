#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll arr[10010], ans, n, k;

int main() {
	scanf(" %lld %lld", &n, &k);
	for (int i = 0; i < k; i++) scanf(" %lld", &arr[i]);
	if (n <= k) {
		printf("%lld\n", n); return 0;
	}
	ll l = 0, r = 2e12;
	while (l <= r) {
		ll mid = (l + r) / 2;
		ll c = k;
		bool check = true;
		for (int i = 0; i < k; i++) {
			c += (mid / arr[i]);
		}
		if (c >= n) {
			ans = mid;
			r = mid - 1;
		}
		else l= mid + 1;
	}
	ll temp = k;
	for (int i = 0; i < k; i++) temp += ((ans - 1) / arr[i]);
	for (int i = 0; i < k; i++) {
		if (ans%arr[i] == 0) {
			temp++;
		}
		if (temp == n) {
			printf("%d\n", i + 1); break;
		}
	}
	
}