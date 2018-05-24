#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 30030	
int p[MAX][20];
int depth[MAX];
int tin[MAX];
int tout[MAX];
int n, m, timer,l;
vector<vector<int>> graph;

void dfs(int x, int par) {
	tin[x] = ++timer;
	p[x][0] = par;
	for (int i = 1; i <= l; i++) p[x][i] = p[p[x][i - 1]][i - 1];
	for (int i = 0; i < graph[x].size(); i++) {
		int next = graph[x][i];
		if (next != par) {
			depth[next] = depth[x] + 1;
			dfs(next, x);
		}
	}
	tout[x] = ++timer;
}

bool upper(int x, int y) {
	return (tin[x] <= tin[y] && tout[x] >= tout[y]);
}

int lca(int x, int y) {
	if (upper(x, y)) return x;
	if (upper(y, x)) return y;
	for (int i = l; i >= 0; i--) {
		if (!upper(p[x][i], y)) x = p[x][i];
	}
	return p[x][0];
}

int main() {
	scanf("%d", &n);
	graph.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int x, y; scanf("%d %d", &x, &y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (l = 1; (1 << l) <= n; l++);
	dfs(1, 1);

	int ans = 0;
	int pos = 1;
	int next = 0;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf(" %d", &next);
		int LCA = lca(pos, next);
		ans += (depth[pos] - depth[LCA]);
		ans += (depth[next] - depth[LCA]);
		pos = next;
	}
	printf("%d\n", ans);
}