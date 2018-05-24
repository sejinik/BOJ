#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;
int num[20002];
int low[20002];
bool check[20002];
int com[20002];
int n, m, cnt, sn;
vector<vector<int>> graph;
stack<int> st;
queue<int> q;

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
			check[y] = false;
			com[y] = sn;
			if (x == y) break;
		}
		sn++;
	}
}
int op(int x) {
	if (x > n) return x - n;
	else return x + n;
}
int main() {
	scanf("%d %d", &n, &m);
	graph.resize(2 * n + 5);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		if (a < 0) a = -a + n;
		if (b < 0) b = -b + n;
		graph[op(a)].push_back(b);
		graph[op(b)].push_back(a);
	}
	for (int i = 1; i <= n*2; i++)
		if (num[i] == 0) dfs(i);

	bool ok = true;
	for (int i = 1; i <= n; i++) {
		if (com[i] == com[i + n]) {
			ok = false;
		}
	}
	
	if (ok) puts("1");
	else puts("0");
	return 0;
}