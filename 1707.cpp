#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

vector<int> vt[20010];
int visited[20010];

void dfs(int here, int c) {
	visited[here] = c;
	for (int i = 0; i < vt[here].size(); i++) {
		int there = vt[here][i];
		if (visited[there] == 0)
			dfs(there, 3 - c);
	}
}

int main() {
	int Tcase;
	scanf("%d", &Tcase);

	while (Tcase--) {
		int point, node;
		scanf("%d %d", &point, &node);

		for (int i = 1; i <= point; i++)
			vt[i].clear();
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < node; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			vt[a].push_back(b);
			vt[b].push_back(a);
		}

		for (int i = 1; i <= point; i++) {
			if (visited[i] == 0)
				dfs(i,1);
		}
		
		bool ans = true;
		for (int i = 1; i <= point; i++) {
			for (int j = 0; j < vt[i].size(); j++) {
				int cmp = vt[i][j];
				if (visited[i] == visited[cmp])
					ans = false;
			}
		}
		
		if (ans == true)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}


