#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int>q;
	int n, t;
	scanf("%d %d", &n, &t);
	for (int i = 0; i < n; i++) {
		int temp; scanf("%d", &temp);
		q.push(temp);
	}
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		t -= x;
		if (t < 0) break;
		cnt += 1;
	}
	printf("%d\n", cnt);
	return 0;
}