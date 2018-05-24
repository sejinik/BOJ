#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int from_, to_;
vector<vector<pair<int,int>>> vt;
bool check[100100];

void dfs(int from_,int to_,int weight) {
	check[from_] = true;

	for (int i = 0; i < vt[from_].size(); i++) {
		int there = vt[from_][i].first;
		int nweight = vt[from_][i].second;

		if (!check[there] && nweight >= weight) {
			dfs(there, to_, weight);
		}
	}
	
}

int main() {
	scanf("%d%d", &n, &m);
	vt.resize(n + 1);

	int max_a=0;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
			
		vt[u].push_back({ v,w });
		vt[v].push_back({ u,w });

		max_a = max(max_a, w);
	}
	scanf("%d %d", &from_, &to_);

	int right = max_a;
	int left = 1;
	int ans = 0;

	while (left <= right) {
		int mid = (right + left) / 2;
		memset(check, 0, sizeof(check));
		dfs(from_, to_, mid);

		if (check[to_]) {

			if (ans < mid)
				ans = mid;

			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}