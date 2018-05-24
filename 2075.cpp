#include <iostream>
#include <queue>
using namespace std;

int main() {
	priority_queue<int> pq;
	priority_queue<int> pq2;
	int n; scanf("%d", &n);
	for (int i = 0; i < n*n; i++) {
		int temp; scanf("%d", &temp);
		pq.push(-temp);
		if (pq.size() > 1510) pq.pop();
	}
	int s = pq.size();
	while (s--) {
		int a = -pq.top();
		pq.pop();
		pq2.push(a);
	}
	int ans = 0;
	while (n--) {
		ans = pq2.top();
		pq2.pop();
	}
	printf("%d\n", ans);
	return 0;
}