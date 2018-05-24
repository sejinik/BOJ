#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[222];
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &arr[i]);
	vector<int> vt;
	for (int i = 0; i < n; i++) {
		auto p = lower_bound(vt.begin(), vt.end(), arr[i]);
		if (p == vt.end()) vt.push_back(arr[i]);
		else *p = arr[i];
	}
	printf("%d\n", n - vt.size());
	return 0;
}