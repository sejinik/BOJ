#include <iostream>
using namespace std;
int n;

void go(int x) {
	if (x == 0) return;
	if (x % 2 == 0) {
		go(-(x / 2));
		printf("0");
	}
	else {
		if (x > 0) go(-(x / 2));
		else go((-x + 1) / 2);
		printf("1");
	}
}
int main() {
	scanf(" %d", &n);
	if (n == 0) puts("0");
	else go(n);
}