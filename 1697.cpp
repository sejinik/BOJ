#include <iostream>
#include <queue>
using namespace std;

bool visited[100010];
int n, k;
int cnt;

void bfs(int here) {
	queue<int> q;
	visited[here] = true;
	q.push(here);

	while (int s = q.size()) {
		cnt++;
		while (s--) {
			int there = q.front();
			q.pop();

			if (there + 1 <= 100000 && !visited[there+1]) {
				if (there + 1 == k) return;
				q.push(there + 1);
				visited[there + 1] = true;
			}
				
			if (0<= there -1 && there - 1 <= 100000 && !visited[there-1]) {
				if (there - 1 == k) return;
				q.push(there - 1);
				visited[there - 1] = true;
			}

			if (there * 2 <= 100000 && !visited[there*2]) {
				if (there * 2 == k) return;
				q.push(there * 2);
				visited[there * 2] = true;
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);

	if (n == k )
		printf("0\n");


	else {
		bfs(n);
		printf("%d\n", cnt);
	}
	return 0;
}