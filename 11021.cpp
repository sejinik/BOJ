#include <iostream>
using namespace std;

int tcase, a, b;
int cnt = 1;
int main() {
	scanf("%d", &tcase);

	while (tcase--) {
		scanf("%d%d", &a, &b);

		printf("Case #%d: %d\n", cnt++, a + b);
	}
	return 0;
}