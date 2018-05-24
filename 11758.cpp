#include <iostream>
using namespace std;
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int ret = x1*y2 + x2*y3 + x3*y1;
	ret -= (y1*x2 + y2*x3 + y3*x1);
	return ret;
}

int main() {
	int a, b, c, d, e, f;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	int ans = ccw(a, b, c, d, e, f);
	if (ans < 0) puts("-1");
	else if (ans == 0) puts("0");
	else puts("1");
}