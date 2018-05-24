#include <cstdio>

int r, s;

int dx[8] = { 0,0,1,1,1,-1,-1,-1 };
int dy[8] = { 1,-1,0,-1,1,0,-1,1 };

char arr[55][55];
bool check[55][55];

int go(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < r && 0 <= ny && ny < s) {
			if (arr[nx][ny] == 'o')
				cnt += 1;
		}
	}
	return cnt;
}
int main() {
	scanf("%d %d", &r, &s);
	for (int i = 0; i < r; i++) {
		scanf("%s", &arr[i]);
	}

	int _x=0, _y=0;
	int ch = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < s; j++) {
			if (arr[i][j] == '.') {
				int temp = go(i, j);
				if (ch < temp) {
					ch = temp;
					_x = i;
					_y = j;
				}
			}
		}
	}
	arr[_x][_y] = 'o';

	int ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < s; j++) {
			if (arr[i][j] == 'o') {
				ans += go(i, j);
				arr[i][j] = '.';
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}