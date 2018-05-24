#include <iostream>
#include <cstring>
using namespace std;

int arr[51][51];
bool check[51][51];
int cnt;

int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {1,-1,0,-1,1,0,-1,1};

void dfs(int x, int y) {
	check[x][y] = true;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < 50 && 0 <= ny && ny < 50) {
			if (arr[nx][ny] == 1 && check[nx][ny] == false)
				dfs(nx, ny);
		}
	}
}
int main() {
	while (1) {
		int w, h;
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0)
			return 0;
		
		memset(arr, 0, sizeof(arr));
		memset(check, false, sizeof(check));
		cnt = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				int num;
				scanf("%d", &num);
				if (num == 1)
					arr[i][j] = 1;
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] == 1 && check[i][j] == false) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
}