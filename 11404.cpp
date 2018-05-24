#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[110][110];
int n, m, u, v, w;

int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	memset(a, 0x3f, sizeof(a));

	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		a[u][v] = min(a[u][v], w);
	}

	for (int i = 1; i <= n; i++)
		a[i][i] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				a[j][k] = min(a[j][k], a[j][i] + a[i][k]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}