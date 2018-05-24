#include <iostream>
using namespace std;

int arr[11];

int main() {
	int num, price,location;
	scanf("%d %d", &num, &price);

	//1번부터쓴당
	for (int i = 1; i <= num; i++) {
		scanf("%d", &arr[i]);
		if (price >= arr[i])
			location = i;
	}

	int ans = 0;
	for (int i = location; i > 0; i--) {
		ans += price / arr[i];
		price %= arr[i];
	}

	printf("%d\n", ans);
	return 0;
}