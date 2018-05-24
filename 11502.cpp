#include <iostream>
using namespace std;

bool prime[1010];

int num, tcase;

int main() {

	for (int i = 2; i <= 1000; i++) {
		if (prime[i] == false) {
			for (int j = i * 2; j <= 1000; j += i) {
				prime[j] = true;
			}
		}
	}


	scanf("%d", &tcase);

	while (tcase--) {
		scanf("%d", &num);
		bool check = false;
		for (int i = 2; i <= 1000; i++) {
			if (!prime[i]) {
				for (int j = i; j <= 1000; j++) {
					if (!prime[j]) {
						for (int k = j; k <= 1000; k++) {
							if (!prime[k] && (i + j + k) == num) {
								printf("%d %d %d\n", i, j, k);
								check = true;
								break;
							}
						}
						if (check)
							break;
					}
				}
				if (check)
					break;
			}	
		}
	}
	

	return 0;
}