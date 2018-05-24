#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, ans;
bool check[9][9];
int arr[9][9];
int temp_arr[9][9];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> virus;

int cnt() {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp_arr[i][j] == 0)
				ret += 1;
		}
	}
	return ret;
}

void bfs() {
	queue<pair<int, int>> temp;
	for (int i = 0; i < virus.size(); i++) {
		int a = virus[i].first;
		int b = virus[i].second;
		check[a][b] = true;
		temp.push({ a,b });
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp_arr[i][j] = arr[i][j];
		}
	}

	while (!temp.empty()) {
		int x = temp.front().first;
		int y = temp.front().second;
		temp.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (!check[nx][ny] && temp_arr[nx][ny] == 0) {
					check[nx][ny] = true;
					temp_arr[nx][ny] = 2;
					temp.push({ nx,ny });
				}
			}
		}
	}
}

void go(vector<pair<int, int>> &vt, int index, int count) {
	
	if (count == 3) {
		memset(check, 0, sizeof(check));
		bfs();
		ans = max(ans, cnt());
		return;
	}

	if (index >= vt.size()) return;

	int x = vt[index].first;
	int y = vt[index].second;

	arr[x][y] = 1;
	go(vt, index + 1, count + 1);
	
	arr[x][y] = 0;
	go(vt, index + 1, count);
}

int main() {
	vector<pair<int, int>> vt;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2) {
				virus.push_back({ i,j });
			}
			if (arr[i][j] == 0)
				vt.push_back({ i,j });
		}
	}

	bfs();
	ans = max(ans, cnt());

	go(vt, 0, 0);
	printf("%d\n", ans);
	return 0;
}