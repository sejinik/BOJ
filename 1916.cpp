#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int be,en;

int dist[1010];
vector<vector<pair<int, int>>> vt;
priority_queue<pair<int, int>> pq;

int main() {
	memset(dist, -1, sizeof(dist));

	scanf("%d%d", &n, &m);
	vt.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		vt[u].push_back({ v,w });
	}

	scanf("%d%d", &be, &en);

	pq.push({ 0,be });
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (dist[here] != -1)
			continue;
		dist[here] = cost;

		if (here == en) break;

		for (int i = 0; i < vt[here].size(); i++) {
			int next = vt[here][i].first;
			int ncost = -vt[here][i].second - cost;

			if (dist[next] != -1)
				continue;

			pq.push({ ncost,next });
		}
	}
		
	printf("%d\n", dist[en]);
	return 0;
}