#include <iostream>
#include <algorithm>
using namespace std;
#define INF -987654321
int rd[100010];
int ld[100010];
int arr[100010];

int main() {
	int num;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= num; i++) {
		rd[i] = arr[i];
		if (i == 1) continue;
		rd[i] = max(rd[i], rd[i - 1] + arr[i]);
	}

	for (int i = num; i > 0; i--) {
		ld[i] = arr[i];
		if (i == num) continue;
		ld[i] = max(ld[i], ld[i + 1] + arr[i]);
	}

	int ans = arr[1];
	for (int i = 2; i <= num; i++) {
		if (i == num) 
			ans = max({ ans, rd[num-1] +arr[num] ,arr[num] });
		else
			ans = max({ ans, rd[i - 1] + ld[i + 1],rd[i],arr[i]});
	}

		printf("%d\n", ans);
	return 0;
}