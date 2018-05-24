#include <cstdio>

int main() {
	int num = 0;
	for (int i = 0; i < 5; i++) {
		int a;
		scanf("%d", &a);
		num += (a*a);
	}
	num %= 10;
	printf("%d\n", num);
	return 0;
}