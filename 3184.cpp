#include <iostream>	
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int n, m;
char map[255][255];
bool check[255][255];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf(" %s", &map[i]);
	}

	int ans_o = 0;
	int ans_v = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != '#' && !check[i][j]) {
				queue<pair<int, int>> q;
				q.push({ i,j });
				int o = 0;
				int v = 0;
				if (map[i][j] == 'o') o += 1;
				if (map[i][j] == 'v') v += 1;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					check[x][y] = true;

					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (0 <= nx && nx < n && 0 <= ny && ny < m) {
							if (!check[nx][ny]) {
								if (map[nx][ny] == '#') continue;
								if (map[nx][ny] == '.') {
									check[nx][ny] = true;
									q.push({ nx,ny });
								}
								if (map[nx][ny] == 'v') {
									v += 1;
									check[nx][ny] = true;
									q.push({ nx,ny });
								}
								if (map[nx][ny] == 'o') {
									o += 1;
									check[nx][ny] = true;
									q.push({ nx,ny });
								}
							}
						}
					}
				}
				if (o > v) ans_o += o;
				else ans_v += v;
			}
		}
	}
	printf("%d %d\n", ans_o, ans_v);
	return 0;
}