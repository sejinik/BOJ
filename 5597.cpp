#include <iostream>
using namespace std;

bool arr[31];

int main() {
	for (int i = 0; i < 28; i++) {
		int a;
		scanf("%d", &a);
		arr[a] = true;
	}

	for (int i = 1; i < 31; i++) {
		if (arr[i] == false)
			printf("%d\n", i);
	}
	return 0;
}