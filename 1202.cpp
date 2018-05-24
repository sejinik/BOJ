#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
struct node {
	int w, c;
	bool operator < (const node&other)	 const {
		if (c == other.c) return w < other.w;
		return c > other.c;
	}
};
int n, k;
multiset<int> s;
map<int, int> mp;
int main() {
	scanf(" %d %d", &n, &k);
	vector<node> a(n);
	for (int i = 0; i < n; i++) scanf(" %d %d", &a[i].w, &a[i].c);
	sort(a.begin(), a.end());
	for (int i = 0; i < k; i++) {
		int x; scanf(" %d", &x);
		s.insert(x);
		if (mp.count(x)) mp[x]++;
		else mp[x] = 1;
	}
	ll ans = 0;
	int pos = 0;
	while (pos < n && !s.empty()) {
		int  cost = a[pos].c;
		int weight = a[pos].w;
		auto l = s.lower_bound(weight);
		if (l != s.end()) {
			ans += (ll)cost;
			mp[*l]--;
			if (mp[*l] == 0) s.erase(*l);
		}
		pos++;
	}
	printf("%lld\n", ans);
}