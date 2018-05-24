#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
vector<vector<pair<ll, ll>>> graph;
vector<vector<pair<ll, ll>>> nGraph;
ll d[2555][2555];
ll cost[2555];
ll nd[2555];
ll n, m;

int main() {
	memset(d, -1, sizeof(d));
	memset(nd, -1, sizeof(nd));
	scanf(" %lld %lld", &n, &m);
	graph.resize(n+1);
	for (int i = 1; i <= n; i++) scanf(" %lld", &cost[i]);
	for (int i = 0; i < m; i++) {
		ll u, v, cap; scanf(" %lld %lld %lld", &u, &v, &cap);
		graph[u].push_back({ v,cap });
		graph[v].push_back({ u,cap });
	}
	for (int i = 1; i <= n; i++) {
		priority_queue<pair<ll, ll>> pq;
		pq.push({ 0,i });
		while (!pq.empty()) {
			ll here = pq.top().second;
			ll cost = -pq.top().first;
			pq.pop();

			if (d[i][here] != -1) continue;
			d[i][here] = cost;

			for (int k = 0; k < graph[here].size(); k++) {
				ll next = graph[here][k].first;
				ll ncost = -cost - graph[here][k].second;
				if (d[i][next] == -1) pq.push({ ncost,next });
			}
		}
	}
	nGraph.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			nGraph[i].push_back({ j,cost[i] * d[i][j] });
		}
	}

	priority_queue<pair<ll, ll>> pq;
	pq.push({ 0,1 });
	while (!pq.empty()) {
		ll here = pq.top().second;
		ll cost = -pq.top().first;
		pq.pop();

		if (nd[here] != -1) continue;
		nd[here] = cost;

		for (int i = 0; i < nGraph[here].size(); i++) {
			ll next = nGraph[here][i].first;
			ll ncost = -cost - nGraph[here][i].second;
			if (nd[next] == -1) pq.push({ ncost,next });
		}
	}
	printf("%lld\n", nd[n]);
	return 0;
}