#include <iostream>
#include <queue>
using namespace std;
int n;

int main() {
	priority_queue<int> pq;
	scanf("%d", &n);
	while (n--) {
		int num;
		scanf("%d", &num);
		if (!num) {
			if (pq.empty()) puts("0");
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else {
			pq.push(num);
		}
	}
	return 0;
}