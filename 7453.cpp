#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
int n, a[4004], b[4004], c[4004], d[4004];
int main() {
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) scanf(" %d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
	vector<int> suma, sumb;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x = a[i] + b[j];
			suma.push_back(x);
			x = c[i] + d[j];
			sumb.push_back(x);
		}
	}
	sort(suma.begin(), suma.end());
	sort(sumb.begin(), sumb.end());
	ll ans = 0;
	for (int i = 0; i < suma.size(); i++) {
		ans += upper_bound(sumb.begin(), sumb.end(), -suma[i]) - lower_bound(sumb.begin(), sumb.end(),-suma[i]);
	}
	printf("%lld\n", ans);
}