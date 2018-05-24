#include <cstdio>

int n;
int main() {
	scanf("%d", &n);

	int cnt = 0;
	for (int i = 0; i <7; i++) {
		if (n & (1 << i)) {
			cnt += 1;
		}
	}
	printf("%d\n", cnt);
	return 0;
}