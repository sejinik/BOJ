#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int ind[32020];

vector<vector<int>> vt;

int main() {
	scanf("%d %d", &n, &m);
	vt.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		vt[x].push_back(y);
		ind[y] += 1;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0)
			q.push(i);
	}

	for (int i = 0; i < n; i++) {
		int x = q.front();
		q.pop();

		printf("%d ", x);

		for (int i = 0; i < vt[x].size(); i++) {
			int y = vt[x][i];
			ind[y] -= 1;

			if (ind[y] == 0)
				q.push(y);
		}
	}
	printf("\n");
	return 0;
}