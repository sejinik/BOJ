#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int inf = 1e+9;
int d[105][105];
int n, m;

int main() {
	for (int i = 1; i <= 103; i++) {
		for (int j = 1; j <= 103; j++) {
			d[i][j] = inf;
		}
	}
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		d[a][b] = 1;
	}
	for (int i = 1; i <= n; i++) d[i][i] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				d[j][k] = min(d[j][k],d[j][i] + d[i][k]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (d[i][j] == inf && d[j][i] == inf) cnt += 1;
		}
		printf("%d\n", cnt);
	}
}