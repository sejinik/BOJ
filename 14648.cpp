#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll arr[1010];
ll n, q;

int main() {
	scanf("%lld %lld", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
	}
	for (int i = 0; i < q; i++) {
		ll a;
		scanf("%lld", &a);
		if (a == 1) {
			ll x, y;
			scanf("%lld %lld", &x, &y);
			ll sum = 0;
			for (int i = x; i <= y; i++) {
				sum += arr[i];
			}
			printf("%lld\n", sum);
			swap(arr[x], arr[y]);
		}
		else {
			ll x, y, z, t;
			scanf("%lld %lld %lld %lld", &x, &y, &z, &t);
			ll sum1 = 0;
			ll sum2 = 0;
			for (int i = x; i <= y; i++) {
				sum1 += arr[i];
			}
			for (int i = z; i <= t; i++) {
				sum2 += arr[i];
			}
			printf("%lld\n", sum1 - sum2);
		}
	}
	return 0;
}