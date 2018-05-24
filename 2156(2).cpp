#include <iostream>
#include <algorithm>
using namespace std;

int d[10001][2];
int a[10001];

int main() {
	int num;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		scanf("%d", &a[i]);
	}

	d[1][1] = a[1];
	d[2][1] = a[1] + a[2];
	d[2][0] = a[1];
	
	for (int i = 3; i <= num; i++) {
		d[i][1] = max(d[i - 2][0] + a[i - 1] + a[i], d[i - 1][0] + a[i]);
		d[i][0] = max(d[i - 1][0], d[i - 1][1]);
	}

	int ans = max(d[num][0], d[num][1]);
	printf("%d\n", ans);
	return 0;
}