#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;

int tcase;
int l, from_x, from_y, to_x, to_y;
int cnt;
bool visited[303][303];

int dx[8] = { 1,1,2,2,-1,-1,-2,-2 };
int dy[8] = { 2,-2,1,-1,2,-2,1,-1 };

void bfs(int from_x, int from_y) {
	cnt = 0;
	if (from_x == to_x && from_y == to_y) return;

	queue<pair<int, int>> q;
	q.push(make_pair(from_x, from_y));
	visited[from_x][from_y] = true;

	while (int s = q.size()) {
		while (s--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (0 <= nx && nx < l && 0 <= ny && ny < l) {
					if (!visited[nx][ny]) {
						if (nx == to_x && ny == to_y) {
							cnt++;
							return;
						}

						q.push(make_pair(nx, ny));
						visited[nx][ny] = true;
					}
				}
			}
		}
		cnt++;
	}
}


int main() {
	scanf("%d", &tcase);

	while (tcase--) {
		scanf("%d", &l);
		scanf("%d %d %d %d", &from_x, &from_y, &to_x, &to_y);

		memset(visited, 0, sizeof(visited));

		bfs(from_x, from_y);
		printf("%d\n", cnt);
	}
	return 0;
}