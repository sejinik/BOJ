#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int n, m;
int dist[505];
bool check[505];
vector<vector<int>> vt;

int main() {
	scanf("%d %d", &n, &m);
	vt.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vt[a].push_back(b);
		vt[b].push_back(a);
	}
	queue<int> q;
	q.push(1);
	check[1] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < vt[x].size(); i++) {
			int y = vt[x][i];
			if (!check[y]) {
				q.push(y);
				check[y] = true;
				dist[y] = dist[x] + 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (dist[i] != 0  && dist[i] <= 2) {
			cnt += 1;
		}
	}
	printf("%d\n", cnt);
	return 0;
}