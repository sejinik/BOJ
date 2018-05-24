#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
int n, m, cnt, t, scc_num;
bool check[100010];
int num[100010];
int low[100010];
int sn[100010];
int out[100010];
vector<vector<int>> graph;
vector<vector<int>> ans;
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

	if (low[x] == num[x]) {
		vector<int> scc;
		while (!st.empty()) {
			int y = st.top();
			scc.push_back(y);
			check[y] = false;
			st.pop();
			sn[y] = scc_num;
			if (x == y) break;
		}
		ans.push_back(scc);
		scc_num += 1;
	}
}
int main() {
	scanf("%d", &t);
	while (t--) {
		memset(check, 0, sizeof(check));
		memset(num, 0, sizeof(num));
		memset(low, 0, sizeof(low));
		memset(out, 0, sizeof(out));
		scc_num = cnt = 0;
		ans.clear();
		graph.clear();
		while (!st.empty()) st.pop();

		scanf("%d %d", &n, &m);
		graph.resize(n + 1);

		for (int i = 0; i < m; i++) {
			int a, b; scanf("%d %d", &a, &b);
			graph[a].push_back(b);
		}

		for (int i = 1; i <= n; i++) {
			if (num[i] == 0) dfs(i);
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < graph[i].size(); j++) {
				int next = graph[i][j];
				if (sn[i] != sn[next]) out[sn[next]] += 1;
			}
		}
		int ans = 0;
		for (int i = 0; i < scc_num; i++)
			if (out[i] == 0) ans += 1;
		printf("%d\n", ans);
	}
	return 0;
}