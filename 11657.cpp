#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 100000000
int n, m;
int d[505];
int ans[505];
vector < vector<pair<int, int>>> vt;

int main() {
	for (int i = 2; i <= 505; i++) d[i] = INF;
	scanf("%d %d", &n, &m);
	vt.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vt[a].push_back({ b,c });
	}
	d[1] = 0;
	ans[1] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < vt[j].size(); k++) {
				int next = vt[j][k].first;
				int cost = vt[j][k].second;
				if (d[j] != INF && d[next] > d[j] + cost) {
					d[next] = d[j] + cost;
					ans[next] = d[next];
				}
			}
		}
	}
	for (int i = 0; i < 1; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < vt[j].size(); k++) {
				int next = vt[j][k].first;
				int cost = vt[j][k].second;
				if (d[j] != INF && d[next] > d[j] + cost) {
					d[next] = d[j] + cost;
				}
			}
		}
	}
	bool check = true;
	for (int i = 2; i <= n; i++) {
		if (d[i] != INF && d[i] != ans[i]) {
			check = false;
			break;
		}
	}
	if (check) {
		for (int i = 2; i <= n; i++) {
			if (d[i] == INF) d[i] = -1;
			printf("%d\n", d[i]);
		}
	}
	else puts("-1");
}