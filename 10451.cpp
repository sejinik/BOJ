#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> vt[1010];
bool visited[1010];
int cnt;

void dfs(int here) {
	visited[here] = true;
	for (int i = 0; i < vt[here].size(); i++) {
		int there = vt[here][i];
		if (visited[there] == false)
			dfs(there);
	}
}
int main() {
	int Tcase;
	scanf("%d", &Tcase);

	while (Tcase--) {
		int num;
		scanf("%d", &num);

		for (int i = 1; i <= num; i++)
			vt[i].clear();
		memset(visited, false, sizeof(visited));
		cnt = 0;

		for (int i = 1; i <= num; i++) {
			int a;
			scanf("%d", &a);
			vt[i].push_back(a);
		}

		for (int i = 1; i <= num; i++) {
			if (visited[i] == false) {
				dfs(i);
				cnt++;
			}
		}
		printf("%d\n", cnt);

	}
	return 0;
}