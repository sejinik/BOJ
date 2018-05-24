#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
#define ll long long
vector < vector<pair<ll, ll>>> graph;
set<ll> st;
ll n, k;
ll m[10010];
ll s[10010];
ll mcnt, scnt,mdist,sdist;
int main() {
	memset(m, -1, sizeof(m));
	memset(s, -1, sizeof(s));
	scanf(" %lld %lld", &n, &k);
	graph.resize(10005);
	for (int i = 0; i < k; i++) {
		ll u, v, cap; scanf(" %lld %lld %lld", &u, &v, &cap);
		graph[u].push_back({ v,cap });
		graph[v].push_back({ u,cap });
	}
	scanf(" %lld %lld", &mcnt, &mdist);
	for (int i = 0; i < mcnt; i++) {
		ll temp; scanf("%lld", &temp);
		graph[0].push_back({ temp,0 });
		st.insert(temp);
	}

	scanf("%lld %lld", &scnt, &sdist);
	for (int i = 0; i < scnt; i++) {
		ll temp; scanf("%lld", &temp);
		graph[n + 1].push_back({ temp,0 });
		st.insert(temp);
	}

	priority_queue<pair<ll, ll>> pq;
	pq.push({ 0,0 });
	while (!pq.empty()) {
		ll here = pq.top().second;
		ll cost = -pq.top().first;
		pq.pop();

		if (m[here] != -1) continue;
		m[here] = cost;

		for (int i = 0; i < graph[here].size(); i++) {
			ll next = graph[here][i].first;
			ll ncost = -cost - graph[here][i].second;
			if (m[next] == -1) pq.push({ ncost,next });
		}
	}
	pq.push({ 0,n + 1 });
	while (!pq.empty()) {
		ll here = pq.top().second;
		ll cost = -pq.top().first;
		pq.pop();

		if (s[here] != -1) continue;
			s[here] = cost;

		for (int i = 0; i < graph[here].size(); i++) {
			ll next = graph[here][i].first;
			ll ncost = -cost - graph[here][i].second;
			if (s[next] == -1) pq.push({ ncost,next });
		}
	}

	ll ans = 1e+13;
	for (int i = 1; i <= n; i++) {
		if (st.count(i)) continue;
		if ((m[i] <= mdist) && (s[i] <= sdist)) ans = min(ans, m[i] + s[i]);
		
	}
	if (ans == 1e+13) puts("-1");
	else printf("%lld\n", ans);
	return 0;
}