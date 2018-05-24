#include <iostream>
using namespace std;

int d[310][310];
int a[310][310];

int main() {
	int N, M;
	scanf("%d %d ", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &a[i][j]);
			d[i][j] = d[i][j - 1] + a[i][j];
		}
	}

	int Tcase;
	scanf("%d", &Tcase);

	while (Tcase--) {
		int x, y, z, k;
		scanf("%d %d %d %d", &x, &y, &z, &k);

		if (y == k) {
			int ans = 0;
			for (int i = x; i <= z; i++) {
				ans += a[i][y];
			}
			printf("%d\n", ans);
		}

		else if (x == z) {
			int ans = 0;
			ans = d[z][k] - d[x][y] + a[x][y];
			printf("%d\n", ans);
		}
		else if (x == z && y == k)
			printf("%d\n", a[x][y]);

		else {
			int ans = 0;
			for (int i = x; i <= z; i++) {
				ans = ans + d[i][k] - d[i][y - 1];
			}
			printf("%d\n", ans);
		}
	}

	return 0;
}