#include <iostream>
using namespace std;
int n;

int main() {
	scanf("%d", &n);
	int cnt = 1;

	while (n != 1) {
		if (n & 1) n = n * 3 + 1;
		else n /= 2;
		cnt += 1;
	}
	printf("%d\n", cnt);
}