#include <iostream>
using namespace std;
int arr[4] = { 2,3,5,7 };

bool p(int x) {
	for (int i = 2; i*i <= x; i++) {
		if (x%i == 0) return false;
	}
	return true;
}

void go(int x, int c) {
	if (c == 0) printf("%d\n", x);
	for (int i = 1; i < 10; i += 2) {
		int s = x * 10 + i;
		if (p(s)) go(s, c - 1);
	}
}
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < 4; i++) {
		go(arr[i], n - 1);
	}
}