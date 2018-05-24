#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
int num[20002];
int low[20002];
bool check[20002];
int com[20002];
vector<vector<int>> graph;
stack<int> st;
int cnt, sn, n, m;
int op(int x) {
	if (x <= n) return x + n;
	return x - n;
}

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
		while (!st.empty()) {
			int y = st.top();
			st.pop();
			com[y] = sn;
			check[y] = false;
			if (x == y) break;
		}
		sn++;
	}
}
int main() {
	scanf("%d %d", &n, &m);
	graph.resize(n * 2+2);
	for (int i = 0; i < n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		if (a < 0) a = -a + n;
		if (b < 0) b = -b + n;
		graph[op(a)].push_back(b);
		graph[op(b)].push_back(a);
	}

	for (int i = 1; i <= n * 2; i++)
		if (num[i] == 0) dfs(i);

	bool go = true;
	for (int i = 1; i <= n; i++)
		if (com[i] == com[i + n]) go = false;

	if (go) puts("^_^");
	else puts("OTL");
	return 0;

}