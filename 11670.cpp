#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long	
struct Maximumflow {
	ll n;
	ll source, sink;
	vector<vector<ll>>graph;
	vector<bool> check;
	vector<ll> pred;
	Maximumflow(ll n) : n(n) {
		graph.resize(n);
		check.resize(n);
		pred.resize(n, -1);
	}
	void add_edge(ll u, ll v) {
		graph[u].push_back(v);
	}
	bool dfs(ll x) {
		if (x == -1) return true;
		for (ll i = 0; i < graph[x].size(); i++) {
			ll next = graph[x][i];
			if (check[next]) continue;
			check[next] = true;
			if (dfs(pred[next])) {
				pred[next] = x;
				return true;
			}
		}
		return false;
	}
	ll flow() {
		ll ans = 0;
		for (ll i = 0; i < n; i++) {
			fill(check.begin(), check.end(), false);
			if (dfs(i)) ans += 1;
		}
		return ans;
	}
};

ll arr[2555][3];
ll num[2555][2];
bool visited[7777];
int main() {
	ll n; scanf("%lld", &n);
	Maximumflow mf(n * 3);
	vector<pair<ll,ll>> vt;
	for (ll i = 0; i < n; i++) {
		ll a, b; scanf("%lld %lld", &a, &b);
		num[i][0] = a;
		num[i][1] = b;
		
		arr[i][0] = a + b;
		arr[i][1] = a - b;
		arr[i][2] = a * b;

		vt.push_back({ arr[i][0],-1 });
		vt.push_back({ arr[i][1],-1 });
		vt.push_back({ arr[i][2],-1 });
	}

	sort(vt.begin(), vt.end());
	vt.erase(unique(vt.begin(), vt.end()), vt.end());
	for (ll i = 0; i < vt.size(); i++) vt[i].second = i;

	for (ll i = 0; i < vt.size(); i++) {
		for (ll j = 0; j < n; j++) {
			for (ll k = 0; k < 3; k++) {
				if (vt[i].first == arr[j][k]) {
					mf.add_edge(j, vt[i].second);
				}
			}
		}
	}
	if (mf.flow() != n) {
		puts("impossible"); return 0;
	}

	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < mf.pred.size(); j++) {
			if (mf.pred[j] == -1) continue;
			if (mf.pred[j] == i) {
				for (ll k = 0; k < 3; k++) {
					if ((arr[i][k] == vt[j].first) && !visited[vt[j].second]) {
						if (k == 0) printf("%lld + %lld = %lld\n", num[i][0], num[i][1], vt[j].first);
						else if (k == 1) printf("%lld - %lld = %lld\n", num[i][0], num[i][1], vt[j].first);
						else printf("%lld * %lld = %lld\n", num[i][0], num[i][1], vt[j].first);

						visited[vt[j].second] = true;
					}
				}
			}
		}
	}
}