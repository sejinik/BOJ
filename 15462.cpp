#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> Graph;
int n, check[100010],dep[100010],cnt,ans,s,f;
bool isCycle(int x, int d) {
	if (check[x]) {
		if (check[x] == -1) {
			if (cnt == -1) cnt = d - dep[x];
			check[x] = 1;
			return true;
		}
		return false;
	}
	check[x] = -1;
	dep[x] = d;
	for (int i = 0; i < Graph[x].size(); i++)
		if (isCycle(Graph[x][i], d + 1)) {
			check[x] = 1;
			return true;
		}
	check[x] = 1;
	return false;
}
int main() {
	scanf(" %d", &n);
	Graph.resize(n);
	for (int i = 0; i < n; i++) {
		int x; scanf(" %d", &x);
		Graph[i].push_back(--x);
	}
	for (int i = 0; i < n; i++) {
		if (check[i] == 1) continue;
		cnt = -1;
		if (isCycle(i,0)) ans += cnt;
	}
	printf("%d\n", ans);
}