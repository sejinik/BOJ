#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) q.push(i);
	while (q.size() != 1) {
		int x = q.front();
		printf("%d ", x); q.pop();
		x = q.front(); q.pop(); 
		q.push(x);
	}
	printf("%d\n", q.front());
}