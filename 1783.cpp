#include <iostream>
#include <algorithm>
using namespace	 std;
int n, m, ans = 1;

int main() {
	scanf(" %d %d", &n, &m);
	if (n == 1) ans = 1;
	else if (n == 2) {
		if (m <= 2) ans = 1;
		else if (m <= 4) ans = 2;
		else if (m <= 6) ans = 3;
		else ans = 4;
	}
	else {
		if (m == 2) ans = 2;
		else if (m == 3) ans = 3;
		else if (m==4 || m == 5 || m == 6) ans = 4;
		else if (m == 7) ans = 5;
		else {
			ans = 5;
			ans += (m - 7);
		}
	}
	printf("%d\n", ans);
}