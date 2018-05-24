#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
#define inf -1e17

struct node {
	ll start, len, fun, cost;
	bool operator < (const node& other) const {
		return start < other.start;
	}
};
ll l, n, b;
vector<node> vt;
ll d[1010][1010];

ll go(int pos, int s, int c) {
	if (c > b) return inf;
	if (pos == n) {
		if (s == l) return 0;
		else return inf;
	}
	ll&ret = d[s][c];
	if (ret != -1) return ret;
	ret = go(pos + 1, s, c);
	if (vt[pos].start == s) ret = max(go(pos + 1, s + vt[pos].len, +c + vt[pos].cost) + vt[pos].fun, ret);
	return ret;
}
int main() {
	memset(d, -1, sizeof(d));
	scanf(" %lld %lld %lld", &l, &n, &b);
	vt.resize(n);
	for (int i = 0; i < n; i++) scanf(" %lld %lld %lld %lld", &vt[i].start, &vt[i].len, &vt[i].fun, &vt[i].cost);
	sort(vt.begin(), vt.end());
	ll ans = go(0, 0, 0);
	if (ans <=0) puts("-1");
	else printf("%lld\n", ans);
}