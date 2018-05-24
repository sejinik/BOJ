#include <cstdio>
#include <vector>	
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int parent[50005];
int depth[50005];
bool check[50005];

int lca(int x, int y) {
	if (depth[x] < depth[y])
		swap(x, y);

	while (depth[x] != depth[y]) {
		x = parent[x];
	}
	while (x != y) {
		x = parent[x];
		y = parent[y];
	}
	return x;
}
int main() {
	scanf("%d", &n);
	vector<vector<int>> vt(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		vt[u].push_back(v);
		vt[v].push_back(u);
	}
	

	parent[1] = 1;
	check[1] = true;
	depth[1] = 0;

	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < vt[x].size(); i++) {
			int y = vt[x][i];
			if (!check[y]) {
				check[y] = true;
				depth[y] = depth[x] + 1;
				parent[y] = x;
				q.push(y);
			}
		}
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", lca(x, y));
	}
	return 0;
}