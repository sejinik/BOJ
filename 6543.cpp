#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;
int n, m,cnt,sn;
bool check[5005];
int num[5005];
int low[5005];
int com[5005];
int outd[5005];
stack<int> st;
vector<vector<int>> graph;
vector<vector<int>> ans;

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
			com[y] = sn;
			st.pop();
			scc.push_back(y);
			check[y] = false;
			if (x == y) break;
		}
		ans.push_back(scc);
		sn++;
	}
}
int main() {
	while (true) {
		memset(check, 0, sizeof(check));
		memset(num, 0, sizeof(num));
		memset(low, 0, sizeof(low));
		memset(com, 0, sizeof(com));
		memset(outd, 0, sizeof(outd));
		while (!st.empty()) st.pop();
		cnt = sn = 0;

		graph.clear();
		ans.clear();

		scanf("%d", &n);
		if (n == 0) return 0;
		scanf("%d", &m);

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
				if (com[i] != com[next]) outd[com[i]]++;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (outd[com[i]] == 0) printf("%d ", i);
		}
		printf("\n");
	}
}