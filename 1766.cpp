#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int ind[32100];

int main() {
	scanf("%d %d", &n, &m);
	vector<vector<int>> vt(n + 1);

	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		vt[x].push_back(y);
		ind[y] += 1;
	}

	priority_queue<int> pq;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0)
			pq.push(-i);
	}

	for (int i = 0; i < n; i++) {
		int x = -pq.top();
		pq.pop();

		printf("%d ", x);
		for (int i = 0; i < vt[x].size(); i++) {
			int y = vt[x][i];
			ind[y] -= 1;

			if (ind[y] == 0)
				pq.push(-y);
		}
	}
	printf("\n");
	return 0;
}