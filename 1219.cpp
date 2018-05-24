#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
ll inf = -10000000000;
ll n, m, from, to;
ll d[110];
ll cost[110];
bool check[110];
vector < vector<pair<ll, ll>>> vt;

void dfs(ll x) {
	check[x] = true;
	for (int i = 0; i < vt[x].size(); i++) {
		ll y = vt[x][i].first;
		if (!check[y]) dfs(y);
	}
}

int main() {
	for (int i = 0; i <= 105; i++) d[i] = inf;
	scanf("%lld %lld %lld %lld", &n, &from, &to, &m);
	vt.resize(n);
	for (int i = 0; i < m; i++) {
		ll x, y, z;
		scanf("%lld %lld %lld", &x, &y, &z);
		vt[x].push_back({ y,-z });
	}
	for (int i = 0; i < n; i++) scanf("%lld", &cost[i]);
	dfs(from);
	if (check[to]) {
		d[from] = cost[from];
		bool negative_cycle = false;
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < vt[j].size(); k++) {
					int next = vt[j][k].first;
					int ncost = vt[j][k].second;
					if (d[j] != inf && d[next] < d[j] + ncost + cost[next]) {
						d[next] = d[j] + ncost + cost[next];
						ans = d[to];
						if (i == n - 1) {
							negative_cycle = true;
							memset(check, 0, sizeof(check));
							dfs(next);
							if (!check[to]) negative_cycle = false;
						}
					}
					if (negative_cycle) break;
				}
				if (negative_cycle) break;
			}
			if (negative_cycle) break;
		}
		if (negative_cycle)puts("Gee");
		else printf("%lld\n", d[to]);
	}
	else puts("gg");
	return 0;
}