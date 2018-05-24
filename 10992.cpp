#include <iostream>
using namespace std;

int num;

int main() {
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {


		for (int j = i; j < num; j++) {
			printf(" ");
		}

		for (int k = 1; k <= 2 * i - 1; k++) {
			if (k == 1 || k == 2*i-1)
				printf("*");
			else if (i == num)
				printf("*");
			else
				printf(" ");
		}

		printf("\n");
	}
	return 0;
}