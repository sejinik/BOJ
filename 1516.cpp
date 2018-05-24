#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int ind[505];
int cost[505];
int ans[505];

int main() {
	scanf("%d", &n);
	
	vector<vector<int>> vt(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &cost[i]);

		int temp;
		while (scanf("%d", &temp) != EOF) {
			if (temp == -1)
				break;

			vt[temp].push_back(i);
			ind[i] += 1;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			q.push(i);
			ans[i] = cost[i];
		}
	}

	for (int i = 0; i < n; i++) {
		int x = q.front();
		q.pop();
		
		for (int i = 0; i < vt[x].size(); i++) {
			int y = vt[x][i];
			ind[y] -= 1;

			ans[y] = max(ans[y], cost[y] + ans[x]);
			if (ind[y] == 0) {
				q.push(y);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d\n",ans[i]);
	}
	return 0;
}