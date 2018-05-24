#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n,m,cnt;
int from_x, to_x;

bool visited[101];
vector<int> vt[101];

bool dfs(int here) {
	queue<int> q;
	q.push(here);
	visited[here] = true;

	while (int s = q.size()) {
		while (s--) {
			int nx = q.front();
			q.pop();

			for (int i = 0; i < vt[nx].size(); i++) {
				int there = vt[nx][i];

				if (!visited[there]) {
					if (there == to_x) {
						cnt++;
						return true;
					}

					q.push(there);
					visited[there] = true;
				}
			}
		}
		cnt++;
	}
	return false;
}
int main() {
	scanf("%d", &n);
	scanf("%d %d", &from_x, &to_x);
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		vt[u].push_back(v);
		vt[v].push_back(u);
	}

	bool check = dfs(from_x);

	if (check)
		printf("%d\n", cnt);
	else
		printf("-1\n");
	return 0;
}