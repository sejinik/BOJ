#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m, l;

bool go(int mid, vector<int> vt,int k) {
	for (int i = 0; i < n + 1; i++) {
		if (vt[i] > mid) {
			k--;
			vt[i] -= mid;
			i--;
		}
	}
	if (k < 0) return false;
	return true;
}

int main() {
	scanf("%d %d %d", &n, &m, &l);
	vector<int> arr(n + 2);
	vector<int> vt(n + 1);
	for (int i = 0; i < n; i++) scanf(" %d", &arr[i]);
	arr[n] = 0;
	arr[n + 1] = l;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n + 1; i++) vt[i] = arr[i + 1] - arr[i];
	sort(vt.begin(), vt.end());
	int left = 1, right = 100000, ans = 100000;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (go(mid, vt,m)) {
			ans = min(ans, mid); 
			right = mid - 1;
		}
		else left = mid + 1;
	}
	printf("%d\n", ans);
}