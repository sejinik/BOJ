#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

queue<pair<int, int>> q;
char arr[55][55];
int visited[51][51];
string str[55];

int m_dist;
int dist;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int i, int j,int maxx, int maxy) {
	q.push(make_pair(i, j));
	visited[i][j] = 1;

	while (int s = q.size()) {
		while (s--) {
			int qf = q.front().first;
			int qs = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = qf + dx[i];
				int ny = qs + dy[i];

				if (1 <= nx && nx <= maxx && 1 <= ny && ny <= maxy) {
					if (arr[nx][ny] == 'L' && visited[nx][ny] == 0) {
						q.push(make_pair(nx, ny));
						visited[nx][ny] = 1;
					}
				}
			}
		}
		dist++;
	}
}

int main() {
	int x, y;
	scanf("%d %d", &x, &y);

	for (int i = 1; i <= x; i++) {
		char s;
		scanf("%c", &s);
		for (int j = 1; j <= y; j++) {
			char c;
			scanf("%1c", &c);
			arr[i][j] = c;
		}
	}

	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			if (arr[i][j] == 'L') {
				dist = 0;
				memset(visited, 0, sizeof(visited));
				bfs(i, j,x,y);
				m_dist = max(m_dist, dist);
			}
		}
	}

	printf("%d\n", m_dist - 1);

	return 0;
}