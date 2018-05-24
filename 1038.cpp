#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
#define inf 9876543210
ll n;

ll con(ll num) {
	bool ok = true;
	ll cnt = 0;
	ll f = num;
	while (f >= 10) {
		cnt++;
		ll c = f % 100;
		ll a = c / 10;
		ll b = c % 10;
		if (a - 1 != b) ok = false;
		f /= 10;
	}
	if (!ok) return 0;
	ll c = pow(10, cnt);
	num -= num % c;
	if (num / c == 9) {
		cnt += 2;
		num = 0;
	}
	else num += c;
	for (ll i = 1; i < cnt; i++) num += (pow(10, i)*i);
	return num;
	
}
ll check(ll num) {
	ll pos = -1;
	ll f = num;
	while (num != 0) {
		pos++;
		ll c = num % 100;
		ll a = c / 10;
		ll b = c % 10;
		if (a - b >= 2) break;
		num /= 10;
	}
	ll  ret = pow(10, pos);
	f -= f%ret;
	f += ret;
	for (ll i = 1; i < pos; i++) f += pow(10, i)*i;
	return f;
}

ll go(ll pos, ll num) {
	if (num > inf) return -1;
	if (pos == n) return num;
	if (con(num)) return go(pos + 1, con(num));
	return go(pos + 1, check(num));
}

int main() {
	scanf(" %lld", &n);
	printf("%lld \n", go(0, 0));
}