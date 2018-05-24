#include <iostream>
using namespace std;

int main() {
	int Tcase;
	scanf("%d", &Tcase);

	while (Tcase--) {
		int N,sum=0,cnt=1;
		scanf("%d", &N);

		for (int i = 0; i < 6; i++) {
			int a;
			scanf("%d", &a);
			sum += a;
		}
		while (sum <= N) {
			sum = sum * 4;
			cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}