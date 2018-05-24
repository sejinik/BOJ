#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int map[111][111];
bool check[111][111];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int n, m, ans,cnt;
bool go() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j]) return true;
		}
	}
	return false;
}
int dfs(int x, int y) {
	int ret = 0;
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx <= n && 0 <= ny && ny <= m) {
			if (map[nx][ny] == 1) {
				map[nx][ny] = -1; ret++;
			}
			if (map[nx][ny] == 0 && !check[nx][ny]) ret+=dfs(nx, ny);
		}
	}
	return ret;
}
void change() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == -1) map[i][j] = 0;
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &map[i][j]);
		}
	}
	while (go()) {
		memset(check, 0, sizeof(check));
		cnt += 1;
		ans = dfs(0, 0);
		change();
	}
	printf("%d\n", cnt);
	printf("%d\n", ans);
}