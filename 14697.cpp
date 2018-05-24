#include <iostream>
using namespace std;
int a, b, c, n;

int main() {
	scanf("%d %d %d %d", &a, &b, &c, &n);
	for (int i = 0; i <= n/a; i++) {
		for (int j = 0; j <= n / b; j++) {
			for (int k = 0; k <= n / c; k++) {
				if (a*i + b*j + c*k == n) {
					printf("%d\n", 1); return 0;
				}
			}
		}
	}
	printf("%d\n", 0); return 0;
}