#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int parent[100010];
bool check[100010];
int n;
int main() {
	scanf("%d", &n);
	vector<vector<int>> a(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	queue<int> q;
	q.push(1);
	check[1] = true;
	parent[1] = 1;
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (!check[y]) {
				parent[y] = x;
				check[y] = true;
				q.push(y);
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		printf("%d\n", parent[i]);
	}
	return 0;
}