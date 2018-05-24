#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int arr[501][501];




int go(int num) {
	int cnt = 0;
	while (num > 0) {
		int temp = num % 10;
		num /= 10;

		if(temp == 9)
			cnt += 1;
	}
	return cnt;
}

int main() {
	scanf("%d %d", &n, &m);
	int all_nine = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			arr[i][j] = go(arr[i][j]);
			all_nine += arr[i][j];
		}
	}

	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int rnum = 0;
		for (int j = 0; j < m; j++) {
			rnum += arr[i][j];
		}
		ans = max(ans,rnum);
	}

	for (int j = 0; j < m; j++) {
		int cnum = 0;
		for (int i = 0; i < n; i++) {
			cnum += arr[i][j];
		}
		ans = max(ans, cnum);
	}

	printf("%d\n", all_nine - ans);
	return 0;
}