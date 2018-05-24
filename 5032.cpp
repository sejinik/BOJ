#include <cstdio>

int e, f, c;

int main() {
	scanf("%d %d %d", &e, &f, &c);

	int temp = e + f;
	int cnt = 0;
	while (temp >= c) {
		if (temp == c) {
			cnt += 1;
			break;
		}

		cnt += temp / c;
		temp = temp / c + temp%c;
		}
	printf("%d\n", cnt);
	return 0;
}