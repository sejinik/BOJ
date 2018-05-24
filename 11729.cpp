#include <cstdio>
#include <cmath>
using namespace std;
int n;

void solve(int x, int y, int n) {
	if (n == 0) return;

	solve(x, 6 - x - y, n - 1);
	printf("%d %d\n", x, y);
	solve(6 - x - y, y, n - 1);
}

int main() {
	scanf("%d", &n);
	int cnt = pow(2, n) - 1;
	printf("%d\n", cnt);
	
	solve(1, 3, n);
	return 0;
}