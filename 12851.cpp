#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
bool check[100010];
int dist[100010];

int main() {
	int n, k; scanf("%d %d", &n, &k);
	queue<int> q;
	q.push(n);
	int ans = 0;
	while (!q.empty()) {
		int here = q.front();
		q.pop();

		if (here == k) {
			ans += 1;
			continue;
		}
		int next = here + 1;
		if (0 <= next && next <= 100000) {
			if (!check[next]) {
				check[next] = true;
				dist[next] = dist[here] + 1;
				q.push(next);
			}

			else if (check[next] && dist[next] == dist[here] + 1) {
				if (dist[next] != -1) q.push(next);
			}
		}

		next = here - 1;
		if (0 <= next && next <= 100000) {
			if (!check[next]) {
				check[next] = true;
				dist[next] = dist[here] + 1;
				q.push(next);
			}

			else if (check[next] && dist[next] == dist[here] + 1) {
				if (dist[next] != -1) q.push(next);
			}
		}

		next = here * 2;
		if (0 <= next && next <= 100000) {
			if (!check[next]) {
				check[next] = true;
				dist[next] = dist[here] + 1;
				q.push(next);
			}

			else if (check[next] && dist[next] == dist[here] + 1) {
				if (dist[next] != -1) q.push(next);
			}
		}
	}
	printf("%d\n", dist[k]);
	printf("%d\n", ans);
	return 0;
}