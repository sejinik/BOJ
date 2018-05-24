#include <cstdio>
int inf = 1000000000;
int d[404][404];
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <=n; j++)
			d[i][j] = inf;

	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		d[x][y] = z;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
	int ans = inf;
	for (int i = 1; i <= n; i++) {
		if (ans > d[i][i])
			ans = d[i][i];
	}
	if (ans == inf) puts("-1");
	else printf("%d\n", ans);
	return 0;
	
}