#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m;
int map[1010][1010];
int d[1010][1010];


int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0) continue;
			d[i][j] = min({ d[i][j - 1], d[i - 1][j], d[i - 1][j - 1] }) + 1;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans = max(ans, d[i][j]);
		}
	}
	printf("%d\n", ans*ans);
	return 0;
}