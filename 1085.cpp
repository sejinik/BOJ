#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);

	int a, b;
	a = min(x,w - x);
	b = min(y,h - y);
	if (a >= b)
		printf("%d\n", b);
	else
		printf("%d\n", a);
	return 0;
}