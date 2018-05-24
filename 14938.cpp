#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int d[111][111];
int map[111][111];
int arr[111];

int main() {
	memset(d, 0x3f, sizeof(d));
	int n, m, r; scanf("%d %d %d", &n, &m, &r);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	for (int i = 1; i <= n; i++) d[i][i] = 0;
	for (int i = 0; i < r; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		map[a][b] = map[b][a] = c;
		d[a][b] = d[b][a] = c;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int temp = 0;
		for (int j = 1; j <= n; j++) {
			if (d[i][j] <= m) temp += arr[j];
		}
		ans = max(ans, temp);
	}
	printf("%d\n", ans);
	return 0;
}