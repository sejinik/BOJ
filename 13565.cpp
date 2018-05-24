#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
int map[1010][1010];
bool check[1010][1010];
int n, m;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1d", &map[i][j]);
		}
	}
	queue<pair<int, int>> q;
	for (int i = 0; i < m; i++) {
			if (!check[0][i] && !map[0][i]) {
				check[0][i] = true;
				q.push({ 0,i });
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (0 <= nx && nx < n && 0 <= ny && ny < m) {
							if (!check[nx][ny] && !map[nx][ny]) {
								q.push({ nx,ny });
								check[nx][ny] = true;
							}
						}
					}
				}
				for (int j = 0; j < m; j++) {
					if (check[n - 1][j]) {
						puts("YES");
						return 0;
					}
				}
			}	
		}
	puts("NO");
	return 0;
}