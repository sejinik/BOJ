#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
int num[20002];
int low[20002];
bool	check[20002];
int com[20002];
int ind[20002];
int outd[20002];
vector<vector<int>> graph;
vector<vector<int>> ans;
stack<int> st;
int n, m, t, cnt, sn;

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
			scc.push_back(y);
			com[y] = sn;
			check[y] = false;
			if (x == y)break;
		}
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
		memset(outd, 0, sizeof(outd));
		memset(com, 0, sizeof(com));
		graph.clear();
		ans.clear();
		sn = cnt = 0;
		while (!st.empty()) st.pop();

		scanf("%d %d", &n, &m);
		graph.resize(n + 1);
		
		for (int i = 0; i < m; i++) {
			int x, y; scanf("%d %d", &x, &y);
			graph[x].push_back(y);
		}

		for (int i = 1; i <= n; i++) {
			if (num[i] == 0) dfs(i);
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < graph[i].size(); j++) {
				int y = graph[i][j];
				if (com[i] != com[y]) {
					ind[com[y]]++;
					outd[com[i]]++;
				}
			}
		}
		if (sn == 1) puts("0");
		else {
			int oc = 0, ic = 0, ans = 0;
			for (int i = 0; i < sn; i++) {
				if (ind[i] == 0) ic++;
				if (outd[i] == 0) oc++;
			}
			ans += oc;
			ic -= oc;
			if (ic > 0) ans += ic;
			printf("%d\n", ans);
		}
	}
	return 0;
}