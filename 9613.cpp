#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
ll t, n;
ll arr[111];

ll gcd(ll x, ll y) {
	if (y == 0) return x;
	 return gcd(y, x%y);
}

int main() {
	scanf("%lld", &t);
	while (t--) {
		memset(arr, 0, sizeof(arr));
		scanf("%lld", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lld", &arr[i]);
		}

		ll ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ll temp = gcd(arr[i], arr[j]);
				ans += temp;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}