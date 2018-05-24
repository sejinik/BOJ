#include <iostream>
#include <cmath>
using namespace std;
bool prime(int x) {
	if (x <= 1) return false;
	if (x == 2 || x == 3) return true;
	if (x % 2 == 0) return false;
	for (int i = 3; i*i <= x; i += 2)
		if (x%i == 0) return false;
	return true;
}
int main() {
	int n;
	while (scanf(" %d", &n) != -1) {
		if (n < 8) puts("Impossible.");
		else {
			n -= 4;
			int x = sqrt(n);
			bool check = false;
			for (int i = x; i >= 2; i--) {
				if (prime(i) && prime(n - i)) {
					printf("%d %d %d %d\n", 2, 2, i, n - i);
					check = true; break;
				}
			}
			if (check) continue;
			n -= 1;
			x = sqrt(n);
			for (int i = x; i >= 2; i--) {
				if (prime(i) && prime(n - i)) {
					printf("%d %d %d %d\n", 2, 3, i, n - i);
					check = true;  break;
				}
			}
			if (check) continue;
			n -= 1;
			x = sqrt(n);
			for (int i = x; i >= 2; i--) {
				if (prime(i) && prime(n - i)) {
					printf("%d %d %d %d\n", 3, 3, i, n - i); break;
				}
			}
		}
	}
}