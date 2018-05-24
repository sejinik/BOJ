#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
#define MOD 1000000007;
ll d[55][55][55][55];
ll n, t, k, h;
ll go(ll pos, ll a, ll b, ll c) {
	if (pos == n) {
		if (a == t && b == k && c == h) return 1;
		return 0;
	}
	ll &ret = d[pos][a][b][c];
	if (ret != -1) return ret;
	ret = 0;
	ret += go(pos + 1, a + 1, b, c);
	ret %= MOD;

	ret += go(pos + 1, a, b + 1, c);
	ret %= MOD;

	ret += go(pos + 1, a, b, c + 1);
	ret %= MOD;

	ret += go(pos + 1, a + 1, b + 1, c);
	ret %= MOD;

	ret += go(pos + 1, a, b + 1, c + 1);
	ret %= MOD;

	ret += go(pos + 1, a + 1, b, c + 1);
	ret %= MOD;

	ret += go(pos + 1, a + 1, b + 1, c + 1);
	ret %= MOD;

	return ret;
	
}
int main() {
	memset(d, -1, sizeof(d));
	scanf(" %lld %lld %lld %lld", &n, &t, &k, &h);
	printf("%lld\n", go(0, 0, 0, 0));
	return 0;
}