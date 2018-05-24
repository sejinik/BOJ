#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll n, m, k;
ll a, b, c;
ll d, e, f;
int main() {
	scanf("%lld %lld", &n, &m);
	k = n - m;
	ll num = 5;
	ll two = 2;
	for (ll i = 0; i < 50; i++) {
		a += (n / num);
		b += (m / num);
		c += (k / num);
		d += (n / two);
		e += (m / two);
		f += (k / two);
		two *= 2;
		num *= 5;
	}
	printf("%lld\n", min(a - (b + c),d-(e+f)));
}