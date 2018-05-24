#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[55][55];
int d[55];

int n;

int main() {
	scanf("%d", &n);
	memset(a, 0x3f, sizeof(a));
	while (1) {
		int u, v;
		scanf("%d%d", &u, &v);
		if (u == -1 && v == -1) break;
		a[u][v] = a[v][u] = 1;
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

	for (int k = 1; k < n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (a[i][j] == k)
					d[i] = k;
			}
		}
	}

	int min_ans = 987654321;
	for (int i = 1; i <= n; i++)
		min_ans = min(min_ans, d[i]);

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (min_ans == d[i])
			cnt++;
	}
	printf("%d %d\n", min_ans, cnt);
	for (int i = 1; i <= n; i++)
		if (min_ans == d[i])
			printf("%d ", i);
	printf("\n");
	return 0;

	
}