#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
queue<int> q;

int main() {
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 1; i <= n; i++) q.push(i);

	int round = 0;
	bool fight = false;
	while (int s = q.size()) {
		bool odd = false;
		if (!(s & 1)) s /= 2;
		else {
			s = s / 2 + 1;
			odd = true;
		}
		round += 1;
		while (s--) {
			int x = q.front(); q.pop();
			if (odd && s == 0) {
				q.push(x); break;
			}
			int y = q.front(); q.pop();
			if ((x == a && y == b) || (x == b && y == a)) {
				fight = true; break;
			}
			if (x == a || x == b) q.push(x);
			else if (y == a || y == b) q.push(y);
			else q.push(x);
		}
		if (fight) break;
	}
	if(fight) printf("%d\n", round);
	else printf("%d\n", -1);
	return 0;
}