#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 100010
#define ll long long
ll p[MAX][20];
ll cp[MAX][20];
ll depth[MAX];
ll tin[MAX];
ll tout[MAX];
ll timer, n, m, l;
vector<vector<pair<ll, ll>>> graph;

void dfs(ll x, ll par, ll dist) {
	tin[x] = ++timer;
	p[x][0] = par;
	cp[x][0] = dist;

	for (int i = 1; i <= l; i++) {
		p[x][i] = p[p[x][i - 1]][i - 1];
		cp[x][i] = cp[x][i - 1] + cp[p[x][i - 1]][i - 1];
	}

	for (int i = 0; i < graph[x].size(); i++) {
		ll next = graph[x][i].first;
		ll cost = graph[x][i].second;
		if (next != par) {
			depth[next] = depth[x] + 1;
			dfs(next, x, cost);
		}
	}
	tout[x] = ++timer;
}

bool upper(ll x, ll y) {
	return (tin[x] <= tin[y] && tout[x] >= tout[y]);
}

ll lca(ll x, ll y) {
	if (upper(x, y)) return x;
	if (upper(y, x)) return y;
	for (int i = l; i >= 0; i--) {
		if (!upper(p[x][i], y)) 	x = p[x][i];
	}
	return p[x][0];
}

ll query1(ll x, ll y) {
	ll h = depth[x] - depth[y];
	ll ret = 0;
	for (int i = l; i >= 0; i--) {
		if (h&(1 << i)) {
			ret += cp[x][i];
			x = p[x][i];
		}
	}
	return ret;
}

ll query2(ll x, ll y, ll k) {
	ll LCA = lca(x, y);
	if (k == 1) return x;
	if (k == (depth[x] + depth[y] - 2 * depth[LCA])+1) return y;
	k -= 1;
	if (abs(depth[x] - depth[LCA])> k) {
		for (int i = l; i >= 0; i--) {
			if (k&(1 << i)) {
				x = p[x][i];
			}
		}
		return x;
	}
	else {
		k -= depth[x] - depth[LCA];
		k = depth[y] - depth[LCA] - k;
		for (int i = l; i >= 0; i--) {
			if (k&(1 << i)) {
				y = p[y][i];
			}
		}
		return y;
	}
}


int main() {
	scanf("%lld", &n);
	graph.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		ll x, y, z; scanf("%lld %lld %lld", &x, &y, &z);
		graph[x].push_back({ y,z });
		graph[y].push_back({ x,z });
	}

	for (l = 1; (1 << l) <= n; l++);
	dfs(1, 1, 0);

	scanf("%lld", &m);
	while (m--) {
		ll a; scanf(" %lld", &a);
		if (a == 1) {
			ll x, y; scanf("%lld %lld", &x, &y);
			ll LCA = lca(x, y);
			printf("%lld\n", query1(x, LCA) + query1(y, LCA));
		}
		else {
			ll x, y, k; scanf("%lld %lld %lld", &x, &y, &k);
			printf("%lld\n", query2(x, y, k));
		}
	}
	return 0;
}