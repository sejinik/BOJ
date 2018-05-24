#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
int n, k, f[22], ss[22], acnt, bcnt, na, nb;
int main() {
	scanf(" %d %d", &n, &k);
	for (int i = 0; i < n / 2; i++) scanf(" %d", &f[acnt++]);
	for (int i = n / 2; i < n; i++) scanf(" %d", &ss[bcnt++]);
	vector<int> a, b;
	for (int i = 0; i < (1 << acnt); i++) {
		int s = 0;
		for (int j = 0; j < acnt; j++) {
			if (i&(1 << j)) s += f[j];
		}
		a.push_back(s);
	}
	for (int i = 0; i < (1 << bcnt); i++) {
		int s = 0;
		for (int j = 0; j < bcnt; j++) {
			if (i&(1 << j)) s += ss[j];
		}
		b.push_back(s);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());
	na = a.size(); nb = b.size();
	int l = 0, r = 0;
	ll ans = 0;
	while (l < na && r<nb) {
		int c = a[l] + b[r];
		if (c < k) l++;
		else if (c > k) r++;
		else {
			ll lc = 1, rc = 1;
			l++; r++;
			while (l<na && a[l] == a[l-1]) lc++, l++;
			while (r<nb && b[r]==b[r-1]) rc++, r++;
			ans += (lc*rc);
		}
	}
	printf("%lld\n", k==0 ? ans-1 : ans);
}