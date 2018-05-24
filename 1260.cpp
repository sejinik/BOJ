#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool visited[1010];
vector<vector<int>> vt(1010);
queue<int> q;

void dfs(int n) {
	visited[n] = true;
	printf("%d ", n);

	for (int i = 0; i < vt[n].size(); i++) {
		int y = vt[n][i];
		if (visited[y] == false)
			dfs(y);
	}
}

void bfs(int n) {
	visited[n] = true;
	q.push(n);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		printf("%d ", x);
		for (int i = 0; i < vt[x].size(); i++) {
			int y = vt[x][i];
			if (visited[y] == false) {
				visited[y] = true; q.push(y);
			}
		}
	}
}

int main() {
	int V, E,start;
	scanf("%d %d %d", &V, &E,&start);
	
	for (int i = 0; i < E; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vt[a].push_back(b); 
		vt[b].push_back(a);
	}
	
	for (int i = 1; i <= V; i++) {
		sort(vt[i].begin(), vt[i].end());
	}

	dfs(start);
	printf("\n");
	memset(visited, false, sizeof(visited));
	bfs(start);
	printf("\n");
	return 0;
}