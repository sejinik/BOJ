#include <iostream>
using namespace std;
int in[100010], post[100010], n;

void go(int is, int ie, int ps, int pe) {
	if (is > ie || ps > pe) return;
	int r = post[pe];
	printf("%d ", r);
	go(is, in[r] - 1, ps, ps + in[r] - is - 1);
	go(in[r] + 1, ie, ps + in[r] - is, pe - 1);
}
int main() {
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf(" %d", &x);
		in[x] = i;
	}
	for (int i = 0; i < n; i++) scanf(" %d", &post[i]); 
	go(0, n - 1, 0, n - 1); puts("");
}