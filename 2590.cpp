#include <iostream>
using namespace std;
int arr[7];
int main() {
	for (int i = 1; i <= 6; i++) scanf("%d", &arr[i]);
	int ans = 0;
	ans += arr[6];
	while (arr[5]--) {
		if (arr[1] >0) arr[1] -= 11;
		ans += 1;
	}
	while (arr[4]--) {
		if (arr[2] >0) arr[2] -= 5;
		ans += 1;
	}
	ans += arr[3] / 4;
	arr[3] %= 4;
	if (arr[3] == 3) {
		ans += 1;
		arr[2] -= 1;
		if (arr[2] < 0) arr[1] -= 4 * (-arr[2]);
		arr[1] -= 5;
	}
	else if (arr[3] == 2) {
		ans += 1;
		arr[2] -= 3;
		if (arr[2] < 0) arr[1] -= 4 * (-arr[2]);
		arr[1] -= 6;
	}
	else if (arr[3] == 1) {
		ans += 1;
		arr[2] -= 5;
		if (arr[2] < 0) arr[1] -= 4 * (-arr[2]);
		arr[1] -= 7;
	}
	if (arr[2] > 0) {
		ans += arr[2] / 9;
		arr[2] %= 9;
		if (arr[2] > 0) {
			ans += 1;
			arr[1] -= (36 - arr[2] * 4);
		}
	}

	if (arr[1] > 0) {
		ans += arr[1] / 36;
		arr[1] %= 36;
		if (arr[1] > 0) ans += 1;
	}
	printf("%d\n", ans);
	return 0;
}