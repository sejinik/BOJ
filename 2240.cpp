#include <iostream>
#include <algorithm>
using namespace std;
int t, w;
int arr[1010][2];
int d[1010][2][33];
int main() {
	scanf("%d %d", &t, &w);
	for (int i = 1; i <= t; i++) {
		int temp; scanf("%d", &temp);
		arr[i][temp - 1] += 1;
	}
	d[1][0][0] = arr[1][0];
	d[1][1][1] = arr[1][1];

	for (int i = 0; i <= w; i++) {
		for (int j = 2; j <= t; j++) {
			d[j][0][i] = max(d[j - 1][0][i], d[j - 1][1][i - 1]) + arr[j][0];
			d[j][1][i] = max(d[j - 1][1][i], d[j - 1][0][i - 1]) + arr[j][1];
		}
	}
	int ans = 0;
	for (int i = 0; i <= w; i++) {
		ans = max({ ans,d[t][0][i],d[t][1][w] });
	}
	printf("%d\n", ans);
	return 0;
}