#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct Edge {
	int start, end, cost;
	bool operator < (const Edge& other)	 const {
		return cost < other.cost;
	}
};

int p[1010];
int find(int x) {
	if (x == p[x]) return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	p[y] = x;
}

int main() {
	for (int i = 1; i <= 1010; i++) p[i] = i;
	int n, m, k; scanf("%d %d %d", &n, &m, &k);
	vector<Edge> graph(m+k+1);
	for (int i = 0; i < k; i++) {
		graph[i].start = 0; graph[i].cost = 0;
		scanf(" %d", &graph[i].end);
	}
	for (int i = k; i < k + m; i++) scanf(" %d %d %d", &graph[i].start, &graph[i].end, &graph[i].cost);
	sort(graph.begin(), graph.end());

	int ans = 0;
	for (int i = 0; i < k + m; i++) {
		Edge e = graph[i];
		int x = find(e.start);
		int y = find(e.end);
		if (x != y) {
			merge(x, y);
			ans += e.cost;
		}
	}
	printf("%d\n", ans);
	return 0;
}