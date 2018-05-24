#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
int n, m,a[1010],b[1010],suma[1010],sumb[1010];
ll t;
int main() {
	scanf(" %lld %d", &t, &n);
	for (int i = 1; i <= n; i++) {
		scanf(" %d", &a[i]);
		suma[i] = suma[i - 1] + a[i];
	}
	scanf(" %d", &m);
	for (int i = 1; i <= m; i++) {
		scanf(" %d", &b[i]);
		sumb[i] = sumb[i - 1] + b[i];
	}
	vector<ll> vt1, vt2;
	for (int i = 1; i <= n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			ll x = (ll)suma[i] - (ll)suma[j];
			vt1.push_back(x);
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = i - 1; j >= 0; j--) {
			ll x = (ll)sumb[i] - (ll)sumb[j];
			vt2.push_back(x);
		}
	}
	sort(vt1.begin(), vt1.end());
	sort(vt2.begin(), vt2.end());
	ll ans = 0;
	for (int i = 0; i < vt1.size(); i++) {
		ans += upper_bound(vt2.begin(), vt2.end(), t - vt1[i]) - lower_bound(vt2.begin(), vt2.end(), t - vt1[i]);
	}
	printf("%lld\n", ans);
}