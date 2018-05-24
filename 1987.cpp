#include <iostream>
#include <algorithm>
using namespace std;

int R, C;
char arr[22][22];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
bool alpha[26];

int go(int x, int y) {
	alpha[arr[x][y] - 'A'] = true;

	int ans = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < R && 0 <= ny && ny < C) {
			if (!alpha[arr[nx][ny] - 'A']) {
				alpha[arr[nx][ny] - 'A'] = true;
				int next = go(nx, ny);
				ans = max(ans, next);
				alpha[arr[nx][ny] - 'A'] = false;
			}
		}
	}
	return ans + 1;
}
int main() {
	scanf("%d%d", &R, &C);

	for (int i = 0; i < R; i++)
		scanf("%s", &arr[i]);

	int ans = go(0, 0);

	printf("%d\n", ans);
	return 0;
}