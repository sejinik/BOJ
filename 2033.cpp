#include <cstdio>
int n;

int main() {
	scanf("%d", &n);
	int num = 10;
	while (n > num) {
		
		if ((n % num)>= 5*(num/10)) {
			n -= n%num;
			n += num;
		}
		else {
			n -= n % num;
		}
		num *= 10;
	}
	printf("%d\n", n);
	return 0;
}