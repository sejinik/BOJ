#include <iostream>
using namespace std;

int cute;
int notcute;

int main() {
	int num;
	scanf("%d", &num);

	while (num--) {
		int a=0;
		scanf("%d", &a);
		if (a == 1)
			cute++;
		else
			notcute++;
	}

	if (cute > notcute)
		printf("Junhee is cute!");
	else
		printf("Junhee is not cute!");

		return 0;
}