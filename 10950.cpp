#include <iostream>
using namespace std;

int tcase;
int a, b;

int main() {
	scanf("%d", &tcase);

	while (tcase--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
}