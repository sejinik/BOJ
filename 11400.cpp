#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
vector<vector<int>>graph;
vector<pair<int, int>> ans;
bool check[100010];
int num[100010];
int low[100010];
int par[100010];
int n, m, cnt;

void dfs(int x) {
	if (check[x])	 return;
	check[x] = true;
	num[x] = ++cnt;
	low[x] = cnt;
	int child = 0;
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!check[y]) {
			child += 1;
			par[y] = x;
			dfs(y);
			low[x] = min(low[x], low[y]);
			if (low[y] > num[x]) {
				if (x < y) ans.push_back({ x,y });
				else ans.push_back({ y,x });
			}
		}
		else if (y != par[x]) low[x] = min(low[x], num[y]);
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

	for (int i = 1; i <= n; i++)
		if (!check[i]) dfs(i);

	printf("%d\n", ans.size());
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}