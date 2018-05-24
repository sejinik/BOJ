#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int n;
int arr[101][101];
bool check[101][101];
int ans = 987654321;

void color_dfs(int x, int y,int color) {
	check[x][y] = true;
	arr[x][y] = color;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (arr[nx][ny] == 1 && check[nx][ny] == false) {
				color_dfs(nx, ny, color);
			}
		}
	}
}

int bfs(int _x, int _y,int color) {
	memset(check, 0, sizeof(check));
	queue<pair<int, int>> q;
	q.push({ _x,_y });
	check[_x][_y] = true;

	int ret = 0;
	while (int s = q.size()) {
		while (s--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if (0 <= nx && nx < n && 0 <= ny && ny < n) {
					if (arr[nx][ny] != 0 && arr[nx][ny] != color) return ret;
					if (arr[nx][ny] == 0 &&check[nx][ny] == false) {
						check[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
		ret += 1;
	}
}

bool go(int x, int y) {
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (arr[nx][ny] == 0) {
				return true;
			}
		}
	}
	return false;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int color = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && check[i][j] == false) {
				color_dfs(i, j, color);
				color += 1;
			}
		}
	}
	memset(check, 0, sizeof(check));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != 0) {
				if (go(i, j)) {
					int temp = bfs(i, j, arr[i][j]);
					if (ans > temp)
						ans = temp;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}