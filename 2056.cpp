#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int ind[10010];
int d[10010];
int cost[10010];

int main() {
	scanf("%d", &n);
	vector<vector<int>> vt(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &cost[i]);
		scanf("%d", &m);

		for (int j = 0; j < m; j++) {
			int x;
			scanf("%d", &x);
			vt[x].push_back(i);
			ind[i] += 1;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0)
			q.push(i);
	}

	for (int i = 0; i < n; i++) {
		int x = q.front();
		q.pop();
		d[x] = max(d[x], cost[x]);

		for (int i = 0; i < vt[x].size(); i++) {
			int y = vt[x][i];
			ind[y] -= 1;

			d[y] = max(d[x] + cost[y], d[y]);
			if (ind[y] == 0)
				q.push(y);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, d[i]);
	}
	printf("%d\n", ans);
	return 0;
}