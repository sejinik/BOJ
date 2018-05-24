#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int inf = 100000000;
int t, n, m, w;
int d[505];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &w);
		for (int i = 0; i <= n; i++) d[i] = inf;
		vector<vector<pair<int,int>>> vt(n + 1);
		for (int i = 0; i < m; i++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			vt[x].push_back({ y,z });
			vt[y].push_back({ x,z });
		}
		for (int i = 0; i < w; i++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			vt[x].push_back({ y,-z });
		}
		d[1] = 0;
		bool negative_cycle = false;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 0; k < vt[j].size(); k++) {
					int next = vt[j][k].first;
					int cost = vt[j][k].second;
					if (d[j] != inf && d[next] > d[j] + cost) {
						d[next] = d[j] + cost;
						if (i == n - 1)	 negative_cycle = true;
					}
				}
			}
		}
		if (negative_cycle) puts("YES");
		else puts("NO");
	}
	return 0;
}