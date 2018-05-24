#include <iostream>
using namespace std;

int cnt;
long long ans;
int main() {
	long long num;
	scanf("%lld", &num);

	for (long long i = 1; i <= num; i++) {
		ans += i;
		cnt++;

		if (ans > num) {
			cnt--;
			break;
		}
	}

	printf("%d\n", cnt);
	return 0;
}