#include <iostream>
#include <algorithm>
using namespace std;
int n, m, r, c, d;
int map[55][55];
int check[55][55];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void go(int x, int y,int z) {
	if (x <= 0 || x >= n-1 || y <= 0 || y >= m-1 || map[x][y] == 1) return;
	check[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[(i + (4 - z))%4];
		int ny = y + dy[(i + (4 - z))%4];
		if (0 < nx && nx < n-1 && 0 < ny && ny < m-1) {
			if (check[nx][ny] == 0) {
				go(nx, ny, (z+7-i)%4);
				return;
			}
		}
	}
	go(x + dx[(5 - z) % 4], y + dy[(5 - z) % 4], z);
}

int ans() {
	int ret = 0;
	for (int i = 1; i < n-1; i++) {
		for (int j = 1; j < m-1; j++) {
			if (map[i][j] != check[i][j]) ret += 1;
		}
	}
	return ret;
}
int main() {
	scanf("%d %d %d %d %d", &n, &m, &r, &c, &d);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			check[i][j] = map[i][j];
		}
	}
	go(r, c, d);
	printf("%d\n", ans());
	return 0;
}