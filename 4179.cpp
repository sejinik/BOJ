#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, m;
int inf = 1000000000;
char map[1010][1010];
int dist[1010][1010];
bool  fcheck[1010][1010];
bool scheck[1010][1010];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int main() {

		int from_x = 0, from_y = 0;
		int to_x = 0, to_y = 0;
		queue<pair<int, int>> fq, sq;
		memset(map, 0, sizeof(map));
		memset(dist, 0, sizeof(dist));
		memset(fcheck, 0, sizeof(fcheck));
		memset(scheck, 0, sizeof(scheck));
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf(" %1c", &map[i][j]);
				if (map[i][j] == 'J') {
					sq.push({ i,j });
					dist[i][j] = 1;
					scheck[i][j] = true;
				}
				if (map[i][j] == 'F') {
					fq.push({ i,j });
					fcheck[i][j] = true;
				}
			}
		}
		while (true) {
			int fz = fq.size();
			int sz = sq.size();
			if (sz == 0 && fz == 0) break;

			while (fz--) {
				int x = fq.front().first;
				int y = fq.front().second;
				fq.pop();

				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (0 <= nx && nx < n && 0 <= ny && ny < m) {
						if (map[nx][ny] == '#') continue;
						if (fcheck[nx][ny]) continue;
						fcheck[nx][ny] = true;
						map[nx][ny] = '*';
						fq.push({ nx,ny });
					}
				}
			}

			while (sz--) {
				int x = sq.front().first;
				int y = sq.front().second;
				sq.pop();

				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (0 <= nx && nx < n && 0 <= ny && ny < m) {
						if (map[nx][ny] == '*') continue;
						if (map[nx][ny] == '#') continue;
						if (scheck[nx][ny]) continue;
						scheck[nx][ny] = true;
						dist[nx][ny] = dist[x][y] + 1;
						sq.push({ nx,ny });
					}
				}
			}
		}
		int ans = inf;
		for (int i = 0; i < m; i++) {
			if (dist[0][i] != 0 && ans > dist[0][i])
				ans = dist[0][i];
			if (dist[n - 1][i] != 0 && ans > dist[n - 1][i])
				ans = dist[n - 1][i];
		}
		for (int i = 0; i < n; i++) {
			if (dist[i][0] != 0 && ans > dist[i][0])
				ans = dist[i][0];
			if (dist[i][m - 1] != 0 && ans > dist[i][m - 1])
				ans = dist[i][m - 1];
		}
		if (ans == inf) puts("IMPOSSIBLE");
		else printf("%d\n", ans);
	return 0;
}