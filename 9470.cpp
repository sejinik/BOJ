#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int tcase;
int k, n, m;

int ind[1001];
int lev[1001];

int main() {
	scanf("%d", &tcase);
	while (tcase--) {
		scanf("%d %d %d", &k, &n, &m);
		vector<vector<int>> manage_lev(n + 1);
		vector<vector<int>> vt(n + 1);
		for (int i = 0; i < m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			vt[x].push_back(y);
			ind[y] += 1;
		}

		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (ind[i] == 0) {
				q.push(i);
				lev[i] = 1;
			}
		}

		for (int i = 0; i < n; i++) {
			int x = q.front();
			q.pop();

			for (int i = 0; i < vt[x].size(); i++) {
				int y = vt[x][i];
				ind[y] -= 1;
				manage_lev[y].push_back(lev[x]);

				if (ind[y] == 0) {
					q.push(y);
					if (manage_lev[y].size() == 1)
						lev[y] = lev[x];
					else {
						sort(manage_lev[y].rbegin(), manage_lev[y].rend());
						if (manage_lev[y][0] == manage_lev[y][1])
							lev[y] = manage_lev[y][0] + 1;
						else
							lev[y] = manage_lev[y][0];
					}
				}
			}
		}
		printf("%d %d\n", k, lev[n]);
	}
}