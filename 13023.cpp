#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int n, m;
bool check[2020];
bool ans;
vector<vector<int>> vt;

void dfs(int x, int cnt) {
	if (cnt == 5) {
		ans = true;
		return;
	}
	check[x] = true;
	for (int i = 0; i < vt[x].size(); i++) {
		int y = vt[x][i];
		if (!check[y]) dfs(y, cnt + 1);
		if (ans) return;
	}
	check[x] = false;
}
int main() {
	scanf("%d %d", &n, &m);
	vt.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vt[a].push_back(b);
		vt[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		memset(check, 0, sizeof(check));
		dfs(i, 1);
		if (ans) break;
	}
	if (ans) puts("1");
	else puts("0");
	return 0;
}