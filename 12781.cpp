#include <iostream>
using namespace std;
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int ret = x1*y2 + x2*y3 + x3*y1;
	ret -= (y1*x2 + y2*x3 + y3*x1);
	if (ret > 0) return 1;
	else if (ret < 0) return -1;
	else return 0;
}

int main() {
	int a, b, c, d, e, f, g, h;
	scanf(" %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h);
	int fc = ccw(a, b, c, d, e, f);
	int sc = ccw(a, b, c, d, g, h);
	int fans = fc*sc;
	fc = ccw(e, f, g, h, a, b);
	sc = ccw(e, f, g, h, c, d);
	int sans = fc*sc;
	if (fans == -1 && sans == -1) puts("1");
	else puts("0");
}