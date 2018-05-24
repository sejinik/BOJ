#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<vector<int>> adj;
vector<vector<int>> adj_rev;
int component[10001];
bool check[10001];
vector<int> order;

void dfs(int x) {
	check[x] = true;
	for (int i = 0; i < adj[x].size(); i++) {
		int next = adj[x][i];
		if (!check[next]) dfs(next);
	}
	order.push_back(x);
}

void dfs_rev(int x, int cnt) {
	check[x] = true;
	component[x] = cnt;
	for (int i = 0; i < adj_rev[x].size(); i++) {
		int next = adj_rev[x][i];
		if (!check[next]) dfs_rev(next, cnt);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	adj_rev.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int v, e;
		scanf("%d %d", &v, &e);
		adj[v].push_back(e);
		adj_rev[e].push_back(v);
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i]) dfs(i);
	}
	memset(check, 0, sizeof(check));
	reverse(order.begin(), order.end());
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (component[order[i]] == 0) {
			cnt += 1;
			dfs_rev(order[i], cnt);
		}
	}
	printf("%d\n", cnt);
	vector<vector<int>> ans(cnt);
	for (int i = 1; i <= n; i++) {
		ans[component[i] - 1].push_back(i);
	}
	for (int i = 0; i < cnt; i++) {
		sort(ans[i].begin(), ans[i].end());
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			printf("%d ", ans[i][j]);
		}
		printf("-1\n");
	}
	return 0;
}