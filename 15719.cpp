#include <iostream>
#include <bitset>
using namespace std;
bitset <10000001> bt;
int n;

int main() {
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf(" %d", &x);
		bt[x] = ~bt[x];
	}

	for (int i = 1; i <= n; i++) {
		if (!bt[i]) {
			printf("%d\n", i); return 0;
		}
	}
}