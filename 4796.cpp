#include <iostream>
using namespace std;

int l, p, v;
int cnt = 1;
int main() {

	while (cin >> l >> p >> v) {
		if (l == 0 && p == 0 && v == 0) return 0;

		int day = 0;
		day = (v / p) *l;
		if (v%p < l)
			day += v%p;
		else
			day += l;


		printf("Case %d: %d\n", cnt++, day);
	}
	return 0;
}