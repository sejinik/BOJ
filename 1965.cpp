#include <iostream>
#include <algorithm>
using namespace std;

int arr[1010];
int d[1010];

int main() {
	int num;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= num; i++) {
		d[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j] && d[i] < d[j] + 1)
				d[i] = d[j] + 1;
		}
	}

	int ans = 0;
	for (int i = 1; i <= num; i++) {
		ans = max(d[i], ans);
	}
	printf("%d\n", ans);
	return 0;
}