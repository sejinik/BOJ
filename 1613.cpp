#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int inf = 987654321;
int n, m, k;
int ind[404];
int dist[404][404];

int main() {
	scanf("%d %d", &n, &m);
	vector<vector<int>> vt(n + 1);
	vector<int> ans(n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = inf;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vt[a].push_back(b);
		dist[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (dist[a][b] != inf && dist[b][a] == inf) puts("-1");
		else if (dist[a][b] == inf && dist[b][a] != inf) puts("1");
		else if (dist[a][b] == inf && dist[b][a] == inf) puts("0");
	}
	return 0;
}