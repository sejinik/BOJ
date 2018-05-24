#include <iostream>
using namespace std;

int main() {
	int num;
	scanf("%d", &num);

	int cnt = 0;
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			for (int k = 1; k <= num; k++) {
				if ((i + j + k == num) && (j + 2 <= k) && (i % 2 == 0))
					cnt++;
			}
		}
	}

	printf("%d\n", cnt);
	return 0;
}