#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
vector<vector<int>> graph;
bool check[10010];
int num[10010];
int low[10010];
int parent[10010];
int cut[10010];
int cnt;

void dfs(int x) {
	if (check[x]) return;
	check[x] = true;
	num[x] = ++cnt;
	low[x] = cnt;
	int child = 0;
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!check[y]) {
			child += 1;
			parent[y] = x;
			dfs(y);
			low[x] = min(low[x], low[y]);
			
			if (parent[x] == 0 && child >= 2) cut[x] = true;
			if (parent[x] != 0 && low[y] >= num[x]) cut[x] = true;
		}
		else if (y != parent[x]) low[x] = min(low[x], num[y]);
	}
}
int main() {
	scanf("%d %d", &n, &m);
	graph.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) if (!check[i]) dfs(i);
	int ans = 0;
	for (int i = 1; i <= n; i++) if (cut[i]) ans += 1;
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) if (cut[i]) printf("%d ", i);
	printf("\n");
	return 0;
}