#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int d[22][22][22][22][22];
int map[22][22];
int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int dy[8] = { 1,1,1,0,0,-1,-1,-1 };
int main() {
	scanf(" %d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &map[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[1][i][j][i][j] = 1;
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				int nx = j + dx[i];
				int ny = k + dy[i];
				if (1 <= nx && nx <= n && 1 <= ny && ny <= n) {
					if (map[j][k] == map[nx][ny]) d[2][j][k][nx][ny] = 1;
				}
			}
		}
	}
	
	for (int i = 3; i <= m; i++) {
		for (int x1 = 1; x1 <= n; x1++) {
			for (int y1 = 1; y1 <= n; y1++) {
				for (int x2 = 1; x2 <= n; x2++) {
					for (int y2 = 1; y2 <= n; y2++) {
						if (map[x1][y1] == map[x2][y2]) {
							for (int dir1 = 0; dir1 < 8; dir1++) {
								for (int dir2 = 0; dir2 < 8; dir2++) {
									int nx1 = x1 + dx[dir1];
									int ny1 = y1 + dy[dir1];
									int nx2 = x2 + dx[dir2];
									int ny2 = y2 + dy[dir2];
									if (1 <= nx1 && nx1 <= n && 1 <= ny1 && ny1 <= n && 1 <= nx2 && nx2 <= n && 1 <= ny2 && ny2 <= n) {
										if(map[nx1][ny1] == map[nx2][ny2]) d[i][x1][y1][x2][y2] += d[i - 2][nx1][ny1][nx2][ny2];
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				for (int z = 1; z <= n; z++) {
					ans += d[m][i][j][k][z];
				}
			}
		}
	}
	printf("%d\n", ans);
}
