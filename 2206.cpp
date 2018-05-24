#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int n, m;
bool arr[1010][1010];
bool visited[1010][1010][2];
int dist[1010][1010][2];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int x, int y,int layer) {
	queue < pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(x, y), layer));
	visited[x][y][layer] = 1;
	dist[x][y][layer] = 1;

	while (!q.empty()) {
		int _x = q.front().first.first;
		int _y = q.front().first.second;
		int _layer = q.front().second;
		q.pop();
		
		if (_x == n && _y == m) return;
		for (int i = 0; i < 4; i++) {
			int nx = _x + dx[i];
			int ny = _y + dy[i];


			if (1 <= nx && nx <= n && 1 <= ny && ny <= m) {

				//벽을한번도안만났을때
				if (_layer == 0) {
					//길이라면
					if (arr[nx][ny] == 0) {
						if (!visited[nx][ny][0]) {
							visited[nx][ny][0] = 1;
							dist[nx][ny][0] = dist[_x][_y][0] + 1;
							q.push(make_pair(make_pair(nx, ny), 0));
						}
					
					}
					//벽이라면
					else if (arr[nx][ny] == 1) {
						if (!visited[nx][ny][1]) {
							visited[nx][ny][1] = 1;
							dist[nx][ny][1] = dist[_x][_y][0] + 1;
							q.push(make_pair(make_pair(nx, ny), 1));
						}
					}
				}
			

				//이미 벽을 부순 뒤
				else {
					if (arr[nx][ny] == 0) {
						if (!visited[nx][ny][1]) {
							visited[nx][ny][1] = 1;
							dist[nx][ny][1] = dist[_x][_y][1] + 1;
							q.push(make_pair(make_pair(nx, ny), 1));
						}
					}
				}
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}


	bfs(1,1,0);
	
	if (dist[n][m][0] != 0 && dist[n][m][1] != 0) {
		printf("%d\n", min(dist[n][m][0], dist[n][m][1]));
	}
	else if (dist[n][m][0] == 0 && dist[n][m][1] != 0) {
		printf("%d\n", dist[n][m][1]);
	}
	else if (dist[n][m][0] != 0 && dist[n][m][1] == 0) {
		printf("%d\n", dist[n][m][0]);
	}
	else
		printf("-1\n");

	return 0;
}