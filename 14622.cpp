#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define ll long long
ll n;
bool prime[5000050];
set<ll> A;
set<ll> B;
ll as, bs;
void pre() {
	for (int i = 2; i <= 5000000; i++) {
		if (!prime[i]) {
			for (int j = i*2; j <= 5000000; j += i) {
				prime[j] = true;
			}
		}
	}
}

ll go(ll x,set<ll>& a,set<ll>& b) {
	if (prime[x]) {
		if (b.size() < 3) return -1000;
		else {
			set<ll>::iterator it = b.end();
			int c = 3; while (c--) it--;
			return -(*it);
		}
	}
	else {
		if (a.count(x) || b.count(x)) return -1000;
	}
	a.insert(x); return 0;
}
int main() {
	pre();
	prime[1] = true;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		ll a, b; scanf("%d %d", &a, &b);
		as += go(a, A, B);
		bs += go(b, B, A);
	}
	if (as < bs) puts("소수 마스터 갓규성");
	else if (as > bs) puts("소수의 신 갓대웅");
	else puts("우열을 가릴 수 없음");
}