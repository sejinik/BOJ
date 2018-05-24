#include <iostream>
using namespace std;

int main() {
	int hour, min;
	scanf("%d %d", &hour, &min);

	if (min >= 45) {
		min -= 45;
	}

	else {
		min += 15;
		if (hour >= 1) {
			hour -= 1;
		}
		else {
			hour = 23;
		}
	}
	printf("%d %d\n", hour, min);

	return 0;
}