#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long 
#define MOD 1000000007

ll powf(ll x, ll y) {
	if (y == 0) return 1;
	if (y % 2 == 1)
		return (x*powf(x, y - 1)) % MOD;
	return powf((x*x) % MOD, y / 2) % MOD;
}

int main() {
	ll n;
	scanf("%lld", &n);
	ll ans = 0;
	while (n--) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		if (b == 0) continue;

		ans += ((a*b) % MOD) * powf(2, b - 1);
		ans %= MOD;
	}
	printf("%lld\n", ans);
	return 0;
}