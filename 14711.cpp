#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
char map[1010][1010];
bool check[1010][1010];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int n;

void go(int x, int y) {
	check[x][y] = true;
	if (map[x][y] == '#') map[x][y] = '.';
	else map[x][y] = '#';

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (map[nx][ny] == '#') map[nx][ny] = '.';
			else map[nx][ny] = '#';
		}
	}
}
int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			map[i][j] = '.';

	for (int i = 0; i < n; i++) {
		char a; scanf(" %1c", &a);
		if(a=='#') go(0,i);
	}
;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i - 1][j] == '#' && !check[i - 1][j]) go(i, j);
			else if (map[i - 1][j] == '.' && check[i - 1][j]) go(i, j);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}