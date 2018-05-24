#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

bool check[1000010];
int dist[1000010];

int F, S, G, U, D;

bool bfs(int here) {
	queue<int> q;
	check[here] = true;
	dist[here] = 0;
	q.push(here);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == G) return true;
		if (x > F) return false;
		int nx = x + U;
		if (1 <= nx && nx <= F) {
			if (!check[nx]) {
				check[nx] = true;
				dist[nx] = dist[x] + 1;
				q.push(nx);
			}
		}

		if (D == 0) continue;
		nx = x - D;
		if (1 <= nx && nx <= F) {
			if (!check[nx]) {
				check[nx] = true;
				dist[nx] = dist[x] + 1;
				q.push(nx);
			}
		}
	}
	return false;
}

int main() {
	memset(dist, -1, sizeof(dist));
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

	bool check = bfs(S);

	if (check) {
		printf("%d\n", dist[G]);
	}

	else if (check == false || dist[G] == -1)
		puts("use the stairs");

	return 0;
}