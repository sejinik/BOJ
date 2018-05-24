#include <iostream>
using namespace std;
int n, m;
int arr[20][20];
bool check[20][20][4];
int dx[4] = { 0,1,1 ,1};
int dy[4] = { 1,1,0 ,-1};
int go(int x, int y, int num, int dr) {
	int ret = 1;
	int nx = x + dx[dr];
	int ny = y + dy[dr];
	if (0 <= nx && nx < 19 && 0 <= ny && ny < 19) {
		if (arr[nx][ny] == num) ret += go(nx, ny, num, dr);
	}
	return ret;
}
void chk(int x, int y, int num, int dr) {
	check[x][y][dr] = true;
	int nx = x + dx[dr];
	int ny = y + dy[dr];
	if (0 <= nx && nx < 19 && 0 <= ny && ny < 19) {
		if (arr[nx][ny] == num) chk(nx, ny, num, dr);
	}
}
int main() {
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			scanf(" %d", &arr[i][j]);
		}
	}
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (arr[i][j] == 0) continue;
			for (int k = 0; k < 4; k++) {
				if (check[i][j][k]) continue;
				int c = go(i, j, arr[i][j], k);
				if (c == 5) {
					printf("%d\n", arr[i][j]);
					if (k == 3) printf("%d %d\n", i + 1 + 4, j + 1 - 4);
					else printf("%d %d\n", i + 1, j + 1);
					return 0;
				}
				else if (c > 5) chk(i, j, arr[i][j], k);
			}
		}
	}
	puts("0");
}