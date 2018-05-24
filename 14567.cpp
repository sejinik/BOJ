#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int ind[1010];
int ans[1010];
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	vector<vector<int>> a(n + 1);

	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		a[x].push_back(y);
		ind[y] += 1;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) 
		if (!ind[i]) {
			q.push(i);
			ans[i] = 1;
		}
	int cnt = 2;
	while (int s = q.size()) {
		while (s--) {
			int x = q.front();
			q.pop();
			for (int y : a[x]) {
				ind[y] -= 1;
				if (!ind[y]) {
					q.push(y);
					ans[y] = cnt;
				}
			}
		}
		cnt += 1;
	}
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}