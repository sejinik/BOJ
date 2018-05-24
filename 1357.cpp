#include <iostream>
#include <deque>
using namespace std;

int N, M;

int Rev(int x) {
	deque<int> dq;

	while (x > 0) {
		dq.push_back(x % 10);
		x /= 10;
	}

	int size = dq.size();
	int ret = 0;
	
	while (!dq.empty()) {
		ret *= 10;
		ret += dq.front();
		dq.pop_front();
	}

	return ret;
}

int main() {
	scanf("%d%d", &N, &M);
	int ans = Rev((Rev(N) + Rev(M)));
	printf("%d\n", ans);
	return 0;
}