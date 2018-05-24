#include <iostream>
#include <algorithm>
using namespace std;
int arr[22], pos[22], cnt[4], n, maxn=-1e9, minn = 1e9;
int main() {
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) scanf(" %d", &arr[i]);
	for (int i = 0; i < 4; i++) scanf(" %d", &cnt[i]);
	int p = 0;
	for (int i = 0; i < 4; i++) {
		while (cnt[i] != 0) {
			pos[p++] = i; cnt[i]--;
		}
	}
	do {
		int ans = arr[0];
		bool check = false;
		for (int i = 0; i < n - 1; i++) {
			if (pos[i] == 0) ans = ans + arr[i + 1];
			else if (pos[i] == 1) ans = ans - arr[i + 1];
			else if (pos[i] == 2) ans = ans * arr[i + 1];
			else {
				if (ans < 0) ans = -((-ans) / arr[i + 1]);
				else ans = ans / arr[i + 1];
			}
		}
		maxn = max(ans, maxn);
		minn = min(ans, minn);
	} while (next_permutation(pos, pos + n - 1));
	printf("%d\n%d\n", maxn, minn);
	return 0;
}