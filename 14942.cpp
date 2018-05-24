#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100010
#define ll long long
bool check[MAX];
int p[MAX][20];
ll cp[MAX][20];
int parent[MAX];
int depth[MAX];
int dist[MAX];
int Energy[MAX];
int n, m;
vector<vector<pair<int, int>>> graph;

int lca(int x) {
	int ene = Energy[x];
	int l = 1;
	for (l = 1; (1 << l) <= n; l++);

	for (int i = l; i >= 0; i--) {
		if (x == 1) continue;
		if (depth[x] - (1 << i) >= 0) {
			if (ene >= cp[x][i]) {
				ene -= cp[x][i];
				x = p[x][i];
			}
		}
	}
	return x;
}
int main() {
	scanf("%d", &n);
	graph.resize(n + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &Energy[i]);
	for (int i = 0; i < n - 1; i++) {
		int x, y, z; scanf("%d %d %d", &x, &y, &z);
		graph[x].push_back({ y,z });
		graph[y].push_back({ x,z });
	}
	
	queue<int> q;
	q.push(1);
	check[1] = true;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i].first;
			int cost = graph[here][i].second;
			if (!check[next]) {
				check[next] = true;
				parent[next] = here;
				depth[next] = depth[here] + 1;
				dist[next] = cost;
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		p[i][0] = parent[i];
		cp[i][0] = dist[i];
	}

	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 1; i <= n; i++) {
			if (p[i][j - 1] != 0) {
				p[i][j] = p[p[i][j - 1]][j - 1];
				cp[i][j] = cp[i][j - 1] + cp[p[i][j - 1]][j - 1];
			}
		}
	}
	for (int i = 1; i <= n; i++) printf("%d\n", lca(i));
	return 0;
}