#include <cstdio>
#include <cstring>
using namespace std;

int arr[505][505];
int dp[505][505];

int n, m;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int func(int x, int y) {

	if (x == n - 1 && y == m - 1) return 1;

	int& ret = dp[x][y];
	if (ret != -1) return ret;

	ret = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (arr[x][y] > arr[nx][ny])
			ret += func(nx, ny);
	}

	return ret;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	memset(dp, -1, sizeof(dp));

	printf("%d\n", func(0, 0));
	return 0;
}