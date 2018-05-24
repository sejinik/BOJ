#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n, m;
int cycle[111];
vector<vector<int>> Graph;

bool isCycle(int x) {
	if (cycle[x]) {
		if (cycle[x] == -1) return true;
		return false;
	}
	cycle[x] = -1;
	for (int i = 0; i < Graph[x].size(); i++) {
		int next = Graph[x][i];
		if (isCycle(next)) return true;
	}
	cycle[x] = 1;
	return false;
}

int main() {
	scanf(" %d", &n);
	Graph.resize(n);
	for (int i = 0; i < n - 1; i++) {
		scanf(" %d", &m);
		for (int j = 0; j < m; j++) {
			int x; scanf(" %d", &x);
			x--;
			Graph[i].push_back(x);
		}
	}

	if (isCycle(0)) puts("CYCLE");
	else puts("NO CYCLE");
	
}