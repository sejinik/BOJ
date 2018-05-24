#include <cstdio>

int main() {
	
	int ans = 0;
	int pos = 0;
	for (int i = 0; i < 5; i++) {
		int a, b, c, d;
		int temp = 0;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		temp = a + b + c + d;
		if (ans < temp) {
			pos = i + 1;
			ans = temp;
		}
	}
	printf("%d %d\n", pos, ans);
	return 0;
}