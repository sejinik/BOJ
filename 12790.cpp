#include <iostream>
using namespace std;

int main() {
	int Tcase;
	scanf("%d", &Tcase);

	while (Tcase--) {
		int a, b, c, d, e, f, g, h;
		scanf("%d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h);

		a += e;
		b += f;
		c += g;
		d += h;
		
		if (a < 1)
			a = 1;
		if (b < 1)
			b = 1;
		if (c < 0)
			c = 0;

		int ans = a + b * 5 + c * 2 + d * 2;
		printf("%d\n", ans);
	}
	return 0;
}