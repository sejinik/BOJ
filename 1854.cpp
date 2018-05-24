#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int d[1010];
int cnt[1010];

int main() {
	memset(d, -1, sizeof(d));
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vector<vector<pair<int, int>>> graph(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y, z; scanf("%d %d %d", &x, &y, &z);
		graph[x].push_back({ y,z });
	}

	priority_queue<pair<int, int>> pq;
	pq.push({ 0,1 });
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (cnt[here] >= k) continue;
		if (cnt[here] == k - 1) d[here] = cost;
		cnt[here]++;

		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i].first;
			int ncost = -graph[here][i].second - cost;
			pq.push({ ncost,next });
		}
	}
	for (int i = 1; i <= n; i++) {
		if (d[1] == 0 && k != 1) d[1] = -1;
		printf("%d\n", d[i]);
	}
}