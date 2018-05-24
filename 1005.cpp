#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int tcase;
int n, k,res;

int cost[1001];
int ans[1001];
int ind[1001];

int main() {
	scanf("%d", &tcase);
	while (tcase--) {
		memset(ind, 0, sizeof(ind));
		memset(cost, 0, sizeof(cost));
		memset(ans, 0, sizeof(ans));

		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &cost[i]);
		}

		vector<vector<int>> vt(n + 1);
		for (int i = 0; i < k; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			vt[a].push_back(b);
			ind[b] += 1;
		}
		scanf("%d", &res);
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (ind[i] == 0) {
				q.push(i);
				ans[i] = cost[i];
			}
		}

		for (int i = 0; i < n; i++) {
			int x = q.front();
			q.pop();

			for (int i = 0; i < vt[x].size(); i++) {
				int y = vt[x][i];
				ind[y] -= 1;
				ans[y] = max(ans[y], cost[y] + ans[x]);

				if (ind[y] == 0) {
					q.push(y);
				}
			}
		}

		printf("%d\n", ans[res]);
	}
	return 0;
}