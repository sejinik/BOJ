#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int inf = 1e+9;
char map[55][55];
int dist[55][55][1 << 6];
bool check[55][55][1 << 6];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int n, m, from_x, from_y;


int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == '0') from_x = i, from_y = j;
		}
	}
	int ans = inf;
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0,{from_x,from_y} });
	check[from_x][from_y][0] = true;
	while (!q.empty()) {
		int h = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		check[x][y][h] = true;
		if (map[x][y] == '1') ans = min(ans, dist[x][y][h]); 
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (check[nx][ny][h]) continue;
				if (map[nx][ny] == '#') continue;

				if (map[nx][ny] == '.' || map[nx][ny] == '0' || map[nx][ny] == '1') {
					check[nx][ny][h] = true;
					dist[nx][ny][h] = dist[x][y][h] + 1;
					q.push({ h,{nx,ny} });
				}

				if ('a' <= map[nx][ny] && map[nx][ny] <= 'f') {
					int ex = h;
					ex |= (1 << map[nx][ny] - 'a');
					check[nx][ny][ex] = true;
					dist[nx][ny][ex] = dist[x][y][h] + 1;
					q.push({ ex,{nx,ny} });
				}

				if ('A' <= map[nx][ny] && map[nx][ny] <= 'F') {
					if (h&(1 << (map[nx][ny] - 'A'))) {
						check[nx][ny][h] = true;
						dist[nx][ny][h] = dist[x][y][h] + 1;
						q.push({ h,{nx,ny} });
					}
				}
			}
		}
	}
	if (ans == inf) puts("-1");
	else printf("%d\n", ans);
	return 0;
}
