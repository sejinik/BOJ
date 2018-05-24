#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, S, D, F, B, K;
int cnt;

bool visited[100010];
bool police[100010];

bool bfs(int here) {
	queue<int> q;
	visited[here] = true;
	q.push(here);

	while (int s = q.size()) {
		cnt++;
		while (s--) {
			int nx = q.front();
			q.pop();

			//if (0 > nx + F || 0 > nx - B || nx + F > N || nx - B > N) continue;
			if (police[nx]) continue;

			if (0 < nx + F && nx + F <= N && !visited[nx + F]) {
				if (nx + F == D) return true;
				visited[nx + F] = true;
				q.push(nx + F);
			}

			if (0 < nx - B && nx - B <= N && !visited[nx - B]) {
				if (nx - B == D) return true;
				visited[nx - B] = true;
				q.push(nx - B);
			}
			
		}
	}
	return false;
}

int main() {
	scanf("%d %d %d %d %d %d", &N, &S, &D, &F, &B, &K);

	for (int i = 1; i <= K; i++) {
		int num;
		scanf("%d", &num);
		police[num] = true;
	}

	bool check = bfs(S);

	if (check)
		printf("%d\n", cnt);
	else
		puts("BUG FOUND");
	return 0;

}