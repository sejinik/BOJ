#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;

bool go(int mid,vector<int>&arr, vector<int>&cnt_arr) {
	vector<int> temp(m);
	int rcnt = 0, sum = 0, ret = 0;
	for (int i = 0; i < n; i++) {
		ret++;
		sum += arr[i];
		if (sum > mid) {
			if (rcnt >= m) return false;
			ret--; i--;
			temp[rcnt++] = ret;
			sum = ret = 0;
		}
	}
	if (rcnt < m) {
		temp[rcnt] = ret;
		for (int i = 0; i < m; i++) cnt_arr[i] = temp[i];
		return true;
	}
	return false;
}
int main() {
	scanf(" %d %d", &n, &m);
	vector<int> arr(n);
	vector<int> cnt_arr(m);
	int left = 0, right = 300030, ans = 300030;
	for (int i = 0; i < n; i++) {
		scanf(" %d", &arr[i]);
		left = max(left, arr[i]);
	}
	while (left <= right) {
		int mid = (left + right) / 2;
		if (go(mid,arr,cnt_arr)) {
			ans = min(ans, mid);
			right = mid - 1;
		}
		else left = mid + 1;
	}
	printf("%d\n", ans);
	for (int i = 0; i < m; i++) {
		if (cnt_arr[i] == 0) {
			for (int j = i - 1; j >= 0; j--) {
				if (cnt_arr[j] > 1) {
					cnt_arr[j]--; cnt_arr[i]++; break;
				}
			}
		}
	}
	for (int i = 0; i < m; i++) printf("%d ", cnt_arr[i]); puts("");
}