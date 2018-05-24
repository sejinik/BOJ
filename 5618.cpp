#include <iostream>
#include <algorithm>
using namespace std;

int arr[3];

int main() {
	int num;
	scanf("%d", &num);

	int mini = 987654321;
	for (int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
		mini = min(mini, arr[i]);
	}

	for (int i = 1; i <= mini; i++) {
		if (num == 2) {
			if (arr[0] % i == 0 && arr[1] % i == 0)
				printf("%d\n", i);
		}
		else {
			if (arr[0] % i == 0 && arr[1] % i == 0 && arr[2] % i == 0)
				printf("%d\n", i);
		}
	}
	return 0;
	
}