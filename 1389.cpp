#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int cnt;
int dest;
bool visitied[101];
int res[101];

vector<int> vt[101];

void dfs(int here) {
	queue<int> q;
	cnt = 0;
	q.push(here);
	visitied[here] = true;

	while (int s = q.size()) {
		while (s--) {
			int x = q.front();
			q.pop();

			for (int i = 0; i < vt[x].size(); i++) {
				int there = vt[x][i];

				if (!visitied[there]) {
					if (there == dest) {
						cnt++;
						return;
					}
					q.push(there);
					visitied[there] = true;
				}
			}
		}
		cnt++;
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		vt[u].push_back(v);
		vt[v].push_back(u);
	}

	int ans = 987654321;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;

			memset(visitied, 0, sizeof(visitied));
			dest = j;
			dfs(i);
			res[i] += cnt;
		}
		ans = min(res[i], ans);
	}

	for (int i = 1; i <= n; i++)
		if (res[i] == ans) {
			printf("%d\n", i);
			return 0;
		}
}