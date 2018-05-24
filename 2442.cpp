#include <iostream>
using namespace std;

int main() {
	int num;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		for (int j = num-i; j > 0; j--) 
			printf(" ");
		
		for (int j = 1; j <= 2 * i - 1; j++)
			printf("*");

		printf("\n");
	}
	return 0;
}