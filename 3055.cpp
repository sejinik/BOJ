#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m;
char arr[55][55];
int map[55][55];
int dist[55][55];
bool fcheck[55][55];
bool scheck[55][55];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int from_x, from_y, to_x, to_y;
int main() {
	queue<pair<int, int>> q,pq;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1c", &arr[i][j]);
			if (arr[i][j] == '*') {
				fcheck[i][j] = true;
				q.push({ i,j });
			}
			if (arr[i][j] == 'D') to_x = i, to_y = j;
			if (arr[i][j] == 'S') from_x = i, from_y = j;
		}
	}
	pq.push({ from_x,from_y });
	scheck[from_x][from_y] = true;
	while (true) {
		int qs = q.size();
		int pqs = pq.size();
		if (qs == 0 && pqs == 0) break;
		while (qs--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < n && 0 <= ny && ny < m) {
					if (arr[nx][ny] == 'D') continue;
					if (arr[nx][ny] == 'X') continue;
					if (fcheck[nx][ny])  continue;
					fcheck[nx][ny] = true;
					arr[nx][ny] = '*';
					q.push({ nx,ny });
				}
			}
		}
		while (pqs--) {
			int x = pq.front().first;
			int y = pq.front().second;
			pq.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < n && 0 <= ny && ny < m) {
					if (arr[nx][ny] == '*') continue;
					if (arr[nx][ny] == 'X') continue;
					if (scheck[nx][ny]) continue;
					scheck[nx][ny] = true;
					dist[nx][ny] = dist[x][y] + 1;
					pq.push({ nx,ny });
				}
			}
		}
	}
	if (dist[to_x][to_y] == 0) puts("KAKTUS");
	else printf("%d\n", dist[to_x][to_y]);
	return 0;
}