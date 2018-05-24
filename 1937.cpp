#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int arr[501][501];
int day[501][501];
int ans;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int go(int x, int y) {

	int &ret = day[x][y];
	if (ret != -1) return ret;

	ret = 1;
	int plus = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (arr[nx][ny] > arr[x][y]) {
				int temp = go(nx, ny);
				plus = max(plus, temp);
			}
		}
	}
	ret = ret + plus;
	return ret;
}

int main() {
	scanf("%d", &n);
	memset(day, -1, sizeof(day));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp = go(i, j);
			ans = max(temp, ans);
		}
	}

	printf("%d\n", ans);
	return 0;
}