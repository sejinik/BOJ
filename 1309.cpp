#include <iostream>
using namespace std;

int d[100001];

int main() {
	int num;
	scanf("%d", &num);

	d[1] = 3;
	d[2] = 7;

	for (int i = 3; i <= num; i++) {
		d[i] = 2 * d[i - 1] + d[i - 2];
		d[i] %= 9901;
	}

	printf("%d\n", d[num]);
	return 0;
}