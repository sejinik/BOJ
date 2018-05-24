#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[505][505];
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	memset(a, 0x3f, sizeof(a));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (j == k) continue;
				a[j][k] = min(a[j][k],a[j][i] + a[i][k]);
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);

		if (a[u][v] <= c)
			puts("Enjoy other party");
		else
			puts("Stay here");
	}

	return 0;
}