#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n; scanf("%d", &n);
	int pos = 1;
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) {
			pos = n / i; break;
		}
	}
	printf("%d\n", n-pos);
	return 0;
}