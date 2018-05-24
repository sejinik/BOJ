#include <cstdio>

int l, k, fir, sec, temp;
int arr[1010];
int cnt[1010];
int main() {
	scanf("%d %d", &l, &k);
	
	for (int i = 1; i <= k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (temp < b - a) {
			temp = b - a;
			fir = i;
		}
		for (int j = a; j <= b; j++) {
			if (arr[j] == 0) {
				arr[j] = i;
				cnt[arr[j]] ++;
			}
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= l; i++) {
		if (ans < cnt[i])
			ans = cnt[i];
	}
	for (int i = 1; i <= l; i++) {
		if (ans == cnt[i]) {
			sec = i;
			break;
		}
	}
	printf("%d\n", fir);
	printf("%d\n", sec);
	return 0;
}