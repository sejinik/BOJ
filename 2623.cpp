#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int ind[1001];
int res[1001];
int arr[101];
int cnt;

int main() {
	scanf("%d%d", &n, &m);
	vector<vector<int>> vt(n + 1);
	for (int i = 0; i < m; i++) {
		int num;
		scanf("%d", &num);

		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < num; i++) {
			scanf("%d", &arr[i]);
			if (i == 0) continue;
			vt[arr[i - 1]].push_back(arr[i]);
			ind[arr[i]] += 1;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0)
			q.push(i);
	}

	for (int i = 0; i < n; i++) {
		if (q.empty()) {
			puts("0");
			return 0;
		}

		int x = q.front();
		q.pop();
		res[cnt++] = x;
		for (int i = 0; i < vt[x].size(); i++) {
			int y = vt[x][i];
			ind[y] -= 1;

			if (ind[y] == 0)
				q.push(y);
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", res[i]);
	return 0;
}