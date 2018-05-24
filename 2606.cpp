#include <cstdio>
#include <vector>
using namespace std;

int n, m;
int arr[101];
bool check[101];

vector<vector<int>> vt;

void dfs(int here) {
	check[here] = true;
	for (int i = 0; i < vt[here].size(); i++) {
		int there = vt[here][i];
		if (!check[there])
			dfs(there);
	}
}

int count() {
	int ret = 0;
	for (int i = 1; i <= 100; i++) {
		if (check[i])
			ret += 1;
	}
	return ret-1;
}
int main() {
	scanf("%d %d", &n, &m);
	vt.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		vt[u].push_back(v);
		vt[v].push_back(u);
	}

	dfs(1);
	printf("%d\n", count());
	return 0;
}