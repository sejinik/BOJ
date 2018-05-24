#include <iostream>
using namespace std;

int pow2(int k) {
	return (1 << k);
}

int n, r, c;

int solve(int x, int y, int size) {
	if (size == 1)
		return 2 * x + y;

	else {
		if (x < pow2(size - 1)) {
			if (y < pow2(size - 1)) {
				return solve(x, y, size - 1);
			}
			else {
				return solve(x, y - pow2(size - 1), size - 1) + pow2(2*size-2);
			}
		}

		else {
			if (y < pow2(size - 1)) {
				return solve(x - pow2(size - 1), y, size - 1) + pow2(2 * size - 2) * 2;
			}
			else {
				return solve(x - pow2(size - 1), y - pow2(size - 1), size - 1) + pow2(2 * size - 2) * 3;
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &r, &c);
	
	printf("%d\n",solve(r,c,n));
	return 0;
}