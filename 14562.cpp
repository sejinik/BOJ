#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int c, s, t;

int bfs(int _x, int _y) {
	queue<pair<int, int>> q;
	q.push({ _x,_y });
	if (_x == _y) return 0;
	int cnt = 1;
	while (int s = q.size()) {
		while (s--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x * 2 <= 200 && y + 3 <= 200) {
				q.push({ x * 2,y + 3 });
				if (x * 2 == y + 3) return cnt;
			}

			if (x + 1 <= 200) {
				q.push({ x + 1,y });
				if (x + 1 == y) 	return cnt;
			}
		}
		cnt += 1;
	}
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &c, &s);
		printf("%d\n", bfs(c, s));
	}
	return 0;
}