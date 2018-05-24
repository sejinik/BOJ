#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;


int n;
int arr[101][101];
bool check[101][101];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

bool bfs(int min_num, int max_num) {
	if (max_num < arr[0][0] || arr[0][0] < min_num) return false;

	memset(check, 0, sizeof(check));
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	check[0][0] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (!check[nx][ny]) {
					if (min_num <= arr[nx][ny] && arr[nx][ny] <= max_num) {
						check[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
	}
	return check[n - 1][n - 1];
}

bool go(int mid) {
	for (int i = 0; i + mid <= 200; i++) {
		if (bfs(i, i + mid))
			return true;
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

	int right = 200;
	int left = 0;
	int ans = 200;

	while (left <= right) {
		int mid = (right + left) / 2;

		if (go(mid)) {
			if (ans > mid)
				ans = mid;

			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	printf("%d\n", ans);
	return 0;
}