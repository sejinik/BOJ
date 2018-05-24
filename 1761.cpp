#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int parent[40004];
int depth[40004];
int cost[40004];
bool check[40004];
vector<pair<int,int>> vt[40004];

int lca(int x, int y) {
	int ans = 0;

	if (depth[x] < depth[y])
		swap(x, y);

	while (depth[x] != depth[y]) {
		ans += cost[x];
		x = parent[x];
	}
	while (x != y) {
		ans += cost[x];
		x = parent[x];
		ans += cost[y];
		y = parent[y];
	}
	return ans;
}
int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		vt[u].push_back({ v,w });
		vt[v].push_back({ u,w });
	}

	parent[1] = 1;
	depth[1] = 0;
	cost[1] = 0;
	check[1] = true;

	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < vt[x].size(); i++) {
			int y = vt[x][i].first;
			int ncost = vt[x][i].second;
			if (!check[y]) {
				check[y] = true;
				parent[y] = x;
				depth[y] = depth[x] + 1;
				cost[y] = ncost;
				q.push(y);
			}
		}
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a, b));
	}
	return 0;
}