#include <iostream>
using namespace std;

void func(int x) {
	if (x < 10) {
		printf("%d\n",x);
		return;
	}
	printf("%d ", x);

	int ans = 1;
	while (x >= 10) {
		ans *= (x % 10);
		x /= 10;
	}
	ans *= x;
	func(ans);
}

int main() {
	while (1) {
		int num;
		scanf("%d", &num);
		if (num == 0) return 0;

		func(num);
	}
}