#include <iostream>
using namespace std;

int a, b;

int main() {

	while (scanf("%d%d", &a, &b)) {
		if (a == 0 && b == 0) return 0;
		printf("%d\n", a + b);
	}
}