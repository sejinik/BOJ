#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int num;
	scanf("%d", &num);

	for (int i = 1; i <= num * 2 - 1; i++) {
		for (int j = abs(num - i); j > 0; j--) {
			printf(" ");
		}
		
		for (int k = abs(num - abs(num - i)); k > 0; k--) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}