#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
bool check[100010];

int main() {
	int n, k; scanf("%d %d", &n, &k);
	queue<int> fq;
	queue<int> sq;

	fq.push(n);
	check[n] = true;
	int t = 0;
	while (true) {
		while (!fq.empty()) {
			int here = fq.front();
			fq.pop();

			if (here == k) {
				printf("%d\n", t); return 0;
			}
			int next = here * 2;
			if (0 <= next && next <= 100000)
				if (!check[next]) {
					fq.push(next);
				}

			next = here + 1;
			if (0 <= next && next <= 100000)
				if (!check[next]) {
					sq.push(next);
				}
			next = here - 1;
			if (0 <= next && next <= 100000)
				if (!check[next]) {
					sq.push(next);
				}
		}

		while (!sq.empty()) {
			check[sq.front()] = true;
			fq.push(sq.front());
			sq.pop();
		}
		t += 1;
	}

}