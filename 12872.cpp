#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define MOD 1000000007
ll d[101][101];
ll n, m, p;
ll go(ll pos, ll x) {
	if (pos == p) {
		if (x == n) return 1;
		return 0;
	}
	ll&ret = d[pos][x];
	if (ret != -1) return ret;
	ret = 0;
	ll y = n - x;
	if (y > 0) ret += go(pos + 1, x + 1)*y;
	if (x > m) ret += go(pos + 1, x)*(x - m);
	ret %= MOD;
	return ret;
}
int main() {
	memset(d, -1, sizeof(d));
	scanf(" %lld %lld %lld", &n, &m, &p);
	printf("%lld\n", go(0, 0));
}