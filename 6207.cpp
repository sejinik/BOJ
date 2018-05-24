#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<vector<int>> graph;
bool check[1010];
int dist[1010];
int arr[1010];
int n, m, k;
void dfs(int x) {
	if (check[x]) return;
	check[x] = true;
	dist[x]++;
	for (int i = 0; i < graph[x].size(); i++) dfs(graph[x][i]);
}
int main() {
	scanf(" %d %d %d", &n, &m, &k);
	graph.resize(m);
	for (int i = 0; i < n; i++) scanf(" %d", &arr[i]);
	for (int i = 0; i < k; i++) {
		int a, b; scanf(" %d %d", &a, &b);
		a--; b--;
		graph[a].push_back(b);
	}

	for (int i = 0; i < n; i++) {
		memset(check, 0, sizeof(check));
		arr[i]--;
		dfs(arr[i]);
	}
	int ans = 0;
	for (int i = 0; i < m; i++)
		if (dist[i] == n) ans++;
	printf("%d\n", ans);
}