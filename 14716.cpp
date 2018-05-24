#include <iostream>
using namespace std;
bool check[300][300];
int map[300][300];
int dx[8] = { 0,0,1,1,1,-1,-1,-1 };
int dy[8] = { 1,-1,1,-1,0,1,-1,0 };
int n, m;

void dfs(int x, int y) {
	check[x][y] = true;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			if (map[nx][ny] ==1 && !check[nx][ny])
				dfs(nx, ny);
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] ==1 && !check[i][j]) {
				dfs(i, j);
				ans += 1;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}