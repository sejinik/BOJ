#include <iostream>
using namespace std;

int main() {
	int x, y;

	int a, b, c, d, e;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	x = a*e;
	
	if (c < e) {
		y = b + (e - c)*d;
	}
	else
		y = b;

	if (x > y)
		printf("%d\n", y);
	else
		printf("%d\n", x);
	return 0;
	
}