#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 100001

int n, k;
bool visited[MAX];
int dist[MAX];
int from[MAX];

void bfs(int here) {
	queue<int> q;
	q.push(here);
	visited[here] = true;
	dist[here] = 0;
	
	while (!q.empty()) {
		int x = q.front();
		if (x == k) break;
		q.pop();

		if ((x - 1) >= 0 && (x - 1) < MAX) {
			if (!visited[x - 1]) {
				visited[x - 1] = true;
				dist[x - 1] = dist[x] + 1;
				from[x - 1] = x;
				q.push(x - 1);
			}
		}

		if ((x + 1) < MAX) {
			if (!visited[x + 1]) {
				visited[x + 1] = true;
				dist[x + 1] = dist[x] + 1;
				from[x + 1] = x;
				q.push(x + 1);
			}
		}

		if ((x * 2) < MAX) {
			if (!visited[x * 2]) {
				visited[x * 2] = true;
				dist[x * 2] = dist[x] + 1;
				from[x * 2] = x;
				q.push(x * 2);
			}
		}
	}
}

void print(int n, int m) {
	if (n != m)
		print(n, from[m]);

	printf("%d ", m);
}
int main() {
	scanf("%d%d", &n, &k);
	bfs(n);

	printf("%d\n", dist[k]);
	print(n, k);
	printf("\n");
	return 0;
}