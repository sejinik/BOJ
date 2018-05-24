#include <cstdio>
#include <algorithm>
using namespace std;

bool arr[105][105];
bool visited[105][105];

int n, m, k;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int dfs(int x, int y) {
	visited[x][y] = true;

	int ans = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (visited[nx][ny]) continue;
		if (!arr[nx][ny]) continue;

		ans += dfs(nx, ny);
	}

	return ans;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);

	for (int i = 0; i < k; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		arr[a-1][b-1] = true;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j]) {
				if (!visited[i][j]) {
					int temp = dfs(i, j);
					ans = max(ans, temp);
				}
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}