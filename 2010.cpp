#include <iostream>
using namespace std;

int arr[500010];

int main() {
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}

	int ans = 0;
	for (int i = 0; i < num; i++) {
		ans += (arr[i] - 1);
	}
	ans += 1;
	printf("%d\n", ans);
	return 0;
}