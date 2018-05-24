#include <iostream>
#include <algorithm>
using namespace std;
int arr[1010];

int main() {
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		int num; scanf("%d", &num);
		sum += num;
		arr[num] += 1;
	}
	int cnt = 0;
	int sec = 0;
	for (int i = 0; i < 1010; i++) {
		if (arr[i] > cnt) {
			cnt = arr[i];
			sec = i;
		}
	}
	printf("%d\n", sum / 10);
	printf("%d\n", sec);
	return 0;
}