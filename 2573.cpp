#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int n, m;
int arr[303][303];
int melt[303][303];
bool check[303][303];

int go(int x, int y) {
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			if (arr[nx][ny] == 0) ret += 1;
		}
	}
	return ret;
}

void dfs(int x, int y) {
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			if (arr[nx][ny] != 0 && check[nx][ny] == false) {
				check[nx][ny] = true;
				dfs(nx, ny);
			}
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	int day = 0;
	while (true) {
		memset(check, 0, sizeof(check));
		memset(melt, 0, sizeof(melt));

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0 && check[i][j] == false) {
					dfs(i, j);
					cnt += 1;
				}
			}
		}
		if (cnt >= 2) {
			printf("%d\n", day);
			return 0;
		}
		else if (cnt == 0) {
			puts("0");
			return 0;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0) {
					melt[i][j] = go(i, j);
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] -= melt[i][j];
				if (arr[i][j] < 0) arr[i][j] = 0;
			}
		}

		day += 1;
	}
}