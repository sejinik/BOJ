#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
int num[20020];
int low[20020];
int com[20020];
bool check[20020];
vector<vector<int>> graph;
stack<int> st;
int n, m, cnt, sn;

int oppo(int x) {
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

			check[y] = false;
			com[y] = sn;
			if (x == y) break;
		}
		sn++;
	}
}
int main() {
	scanf("%d %d", &n, &m);
	graph.resize(n * 2+2);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		if (a < 0) a = -a + n;
		if (b < 0) b = -b + n;
		graph[oppo(a)].push_back(b);
		graph[oppo(b)].push_back(a);
	}

	for (int i = 1; i <= n*2; i++)
		if (num[i] == 0) dfs(i);

	bool can = true;
	for (int i = 1; i <= n; i++) {
		if (com[i] == com[i + n]) can = false;
	}
	if (can) puts("1");
	else {
		puts("0"); return 0;
	}

	for (int i = 1; i <= n; i++) {
		if (com[i] < com[i + n]) printf("1 ");
		else printf("0 ");
	}
	puts("");
	return 0;
}