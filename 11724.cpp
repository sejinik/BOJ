#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int>> vt;
int visited[1001];
int cnt;

void dfs(int here) {
	visited[here] = 1;
		
	for (int i = 0; i < vt[here].size(); i++) {
		int there = vt[here][i];
		if (visited[there] == 0)
				dfs(there);
	}
}
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	vt.resize(N + 1);

	for (int i = 1; i <= M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vt[a].push_back(b);
		vt[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) {
			dfs(i);
			cnt++;
		}
	}

	printf("%d\n", cnt);
	return 0;
}