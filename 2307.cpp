#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <map>	
using namespace std;
int d[1111];
int n, m;
int main() {
	map< int,pair<int,int>> mp;
	memset(d, -1, sizeof(d));
	scanf("%d %d", &n, &m);
	vector<vector<pair<int, int>>> graph(n + 2);
	for (int i = 0; i < m; i++) {
		int start, to, cost; scanf("%d %d %d", &start, &to, &cost);
		graph[start].push_back({ to,cost });
		graph[to].push_back({ start,cost });
		mp[i] = { start,to };
	}
	
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,1 });
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (d[here] != -1) continue;
		d[here] = cost;

		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i].first;
			int ncost = -graph[here][i].second - cost;
			if (d[next] == -1) pq.push({ ncost,next });
		}
	}
	int ans = d[n];
	int temp = 0;
	for (int k = 0; k < m; k++) {
		memset(d, -1, sizeof(d));
		pq.push({ 0,1 });
		while (!pq.empty()) {
			int here = pq.top().second;
			int cost = -pq.top().first;
			pq.pop();

			if (d[here] != -1) continue;
			d[here] = cost;

			for (int i = 0; i < graph[here].size(); i++) {
				int next = graph[here][i].first;
				int ncost = -graph[here][i].second - cost;
				if (mp[k].first == here && mp[k].second == next) continue;
				else if (mp[k].first == next && mp[k].second == here) continue;
				if (d[next] == -1) pq.push({ ncost,next });
			}
		}
		if (d[n] == -1) {
			puts("-1"); return 0;
		}
		else temp = max(temp, d[n]);
	}
	printf("%d\n", temp - ans);
	return 0;
}