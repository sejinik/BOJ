#include <iostream>
#include <algorithm>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int n,from,to;
int d[10010];
int arr[10010];
vector<vector<pair<int, int>>> graph;

int main() {
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	graph.resize(10010);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	scanf("%d %d", &from, &to);

	for (int i = 1; i <= n; i++) {
		for (int j = i+arr[i]; j <= 10000; j += arr[i]) 	graph[i].push_back({ j,1 });
		for (int j = i - arr[i]; j > 0; j -= arr[i]) graph[i].push_back({ j,1 });
	}
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,from });
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (d[here] != -1) continue;
		d[here] = cost;
		
		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i].first;
			int ncost = -cost - graph[here][i].second;
			if (d[next] == -1) pq.push({ ncost,next });
		}
	}
	printf("%d\n", d[to]);
	return 0;
}