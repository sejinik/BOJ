#include <iostream>
using namespace std;

int main() {
	int num, sum = 0;
	
	for (int i = 0; i < 4; i++) {
		scanf("%d", &num);
		sum += num;
	}

	printf("%d\n", sum / 60);
	printf("%d\n", sum % 60);

	return 0;
}