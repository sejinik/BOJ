#include <iostream>
#include <algorithm>
using namespace std;
int a, b, c, n;

int main() {
	scanf("%d %d %d", &a, &b, &c);
	while (true) {
		if (a + 1 == b && b + 1 == c) break;
		if (c - b >= b - a) {
			a = c - 1;
			swap(a, b);
			n += 1;
		}
		else {
			c = a + 1;
			swap(b, c);
			n += 1;
		}
	}
	printf("%d\n", n);
	return 0;
}