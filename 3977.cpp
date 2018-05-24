#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;
int t, n, m, cnt, sn;
vector<vector<int>> graph;
vector<vector<int>> ans;
int component[100010];
int num[100010];
int low[100010];
int ind[100010];
bool check[100010];
stack<int> st;
void dfs(int x) {
	if (check[x]) return;
	check[x] = true;
	num[x] = ++cnt;
	low[x] = cnt;
	st.push(x);
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (num[y] == 0) {
			dfs(y);
			low[x] = min(low[x], low[y]);
		}
		else if (check[y]) low[x] = min(low[x], num[y]);
	}
	if (num[x] == low[x]) {
		vector<int> scc;
		while (!st.empty()) {
			int y = st.top();
			st.pop();
			check[y] = false;
			component[y] = sn;
			scc.push_back(y);
			if (x == y) break;
		}
		sort(scc.begin(), scc.end());
		ans.push_back(scc);
		sn++;
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(num, 0, sizeof(num));
		memset(low, 0, sizeof(low));
		memset(check, 0, sizeof(check));
		memset(ind, 0, sizeof(ind));
		graph.clear();
		ans.clear();
		while (!st.empty()) st.pop();
		cnt = sn = 0;

		scanf("%d %d", &n, &m);
		graph.resize(n);

		for (int i = 0; i < m; i++) {
			int a, b; scanf("%d %d", &a, &b);
			graph[a].push_back(b);
		}
		for (int i = 0; i < n; i++)
			if (num[i] == 0) dfs(i);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < graph[i].size(); j++) {
				int next = graph[i][j];
				if (component[i] != component[next]) {
					ind[component[next]]++;
				}
			}
		}

		int zerocnt = 0;
		int pos = 0;
		for (int i = 0; i < sn; i++)
			if (ind[i] == 0) zerocnt += 1,pos=i;

		if (zerocnt == 1) {
			for (int i = 0; i < ans[pos].size(); i++) printf("%d\n", ans[pos][i]);
		}
		else puts("Confused");
		printf("\n");
 	}
	return 0;
}
