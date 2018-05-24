#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	
	for (int i = 2; i <= n; i++) {
		while (n > 0 && (n%i == 0)) {
			n /= i;
			cnt += 1;
		}
	}

	if (cnt == 0) puts("0");
	else {
		int answer = (int)ceil(log2(cnt));
		printf("%d\n", answer);
	}
	return 0;
}