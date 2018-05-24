#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int d[110000];
int n, k, m;
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d %d %d", &n, &k, &m);
	vector<vector<pair<int, int>>> graph(n + m + 1);

	for (int i = n + 1; i <= n + m; i++) {
		for (int j = 0; j < k; j++) {
			int c; scanf(" %d", &c);
			graph[c].push_back({ i,1 });
			graph[i].push_back({ c,0 });
		}
	}

	priority_queue<pair<int, int>> pq;
	pq.push({ 0,1 });
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (d[here] != -1) continue;
		d[here] = cost;
		if (here == n) break;
		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i].first;
			int ncost = -graph[here][i].second - cost;
			if (d[next] == -1) pq.push({ ncost,next });
		}
	}
	if (d[n] != -1) d[n] += 1;
	printf("%d\n", d[n]);
	return 0;
}