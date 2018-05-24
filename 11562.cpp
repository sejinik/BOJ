#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[300][300];

int n, m;
int u, v, b, k;

int main() {
	scanf("%d %d", &n, &m);
	memset(a, 0x3f, sizeof(a));

	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &u, &v, &b);
		
		if (b) {
			a[u][v] = a[v][u] = 0;
		}

		else {
			a[u][v] = 0;
			a[v][u] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
		a[i][i] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (j == k) continue;
				a[j][k] = min(a[j][k], a[j][i] + a[i][k]);
			}
		}
	}

	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int s, e;
		scanf("%d%d", &s, &e);
		printf("%d\n", a[s][e]);
	}
	return 0;

}
