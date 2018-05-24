#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int parent[100010];
int cost[100010];
int depth[100010];
bool check[100010];
int p[100010][18];
int BIG[100010][18];
int SMALL[100010][18];

void lca(int x, int y) {
	if (depth[x] < depth[y])
		swap(x, y);
	int log = 1;
	int big = 0;
	int small = 10000000;
	for (log = 1; (1 << log) <= depth[x]; log++);
	log -= 1;
	for (int i = log; i >= 0; i--) {
		if (depth[x] - (1 << i) >= depth[y]) {
			big =max(big,BIG[x][i]);
			small = min(small,SMALL[x][i]);
			x = p[x][i];
		}
	}
	if (x == y) {
		printf("%d %d\n", small, big);
		return;
	}
	else {
		for (int i = log; i >= 0; i--) {
			if (p[x][i] != 0 && p[x][i] != p[y][i]) {
				big = max({ big,BIG[x][i],BIG[y][i] });
				small = min({ small,SMALL[x][i],SMALL[y][i] });
				x = p[x][i];
				y = p[y][i];
			}
		}
		small = min({ small,cost[x],cost[y] });
		big = max({ big,cost[x],cost[y] });
		printf("%d %d\n", small, big);
		return;
	}
}

int main() {
	scanf("%d", &n);
	vector<vector<pair<int,int>>> vt(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vt[a].push_back({ b,c });
		vt[b].push_back({ a,c });
	}

	queue<int> q;
	q.push(1);
	check[1] = true;
	parent[1] = 1;
	depth[1] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < vt[x].size(); i++) {
			int nx = vt[x][i].first;
			int ncost = vt[x][i].second;

			if (!check[nx]) {
				check[nx] = true;
				parent[nx] = x;
				depth[nx] = depth[x] + 1;
				cost[nx] = ncost;
				q.push(nx);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		p[i][0] = parent[i];
		BIG[i][0] = SMALL[i][0] = cost[i];
	}

	for (int j = 1; (1 << j) < n; j++) {
		for (int i = 1; i <= n; i++) {
			if (p[i][j - 1] != 0) {
				p[i][j] = p[p[i][j - 1]][j - 1];

				BIG[i][j] = max(BIG[i][j - 1], BIG[p[i][j - 1]][j - 1]);
				SMALL[i][j] = min(SMALL[i][j - 1], SMALL[p[i][j - 1]][j - 1]);
			}
		}
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		lca(a, b);
	}
	return 0;
}