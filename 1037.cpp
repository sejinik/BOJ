#include <iostream>
#include <algorithm>
using namespace std;

int arr[51];

int main() {
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + num);

	int ans = 1;
	if (num % 2 == 0) {
		ans = arr[num / 2 - 1] * arr[num / 2];
	}

	else {
		ans = arr[num / 2] * arr[num / 2];
	}
	printf("%d\n", ans);
	return 0;
}