#include <iostream>
#include <queue>
using namespace std;
priority_queue<double> pq;
double ans[7];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		double temp;
		scanf("%lf", &temp);
		pq.push(temp);
		if (pq.size() == 8) pq.pop();
	}

	for (int i = 6; i >=0; i--) {
		ans[i] = pq.top();
		pq.pop();
	}

	for (int i = 0; i < 7; i++)
		printf("%.3lf\n", ans[i]);
	return 0;
}