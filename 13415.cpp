#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
void go(stack<pair<int,int>>&st, int num, bool dr) {
	if (!st.empty()) {
		int t = st.top().first;
		while (t <= num && !st.empty()) {
			st.pop(); 
			if(!st.empty()) t = st.top().first;
		}
	}
	st.push({ num,dr });
}
int main() {
	stack<pair<int,int>> st;
	int n; scanf(" %d", &n);
	vector<int> arr(n,0);
	vector<int> ans(n,0);
	vector<bool> check(n, 0);
	for (int i = 0; i < n; i++) scanf(" %d", &arr[i]);
	int k; scanf(" %d", &k);
	for (int i = 0; i < k; i++) {
		int u, d; scanf(" %d %d", &u, &d);
		u--; d--;
		bool up = true;
		go(st, u, up);
		go(st, d, !up);
	}
	vector<pair<int,int>> vt(st.size());
	int cnt = 0;
	while (!st.empty()) {
		vt[cnt].first = st.top().first;
		vt[cnt].second = st.top().second;
		st.pop(); cnt++;
	}
	reverse(vt.begin(), vt.end());
	sort(arr.begin(), arr.begin() + vt[0].first+1);
	int left = 0,right = vt[0].first;
	int pos = vt[0].first;
	for (int i = 0; i < cnt-1; i++) {
		int num = vt[i].first;
		int up = vt[i].second;
		if (up) {
			for (int j = num; j > vt[i + 1].first; j--) {
				ans[pos] = arr[right];
				check[right] = true;
				right--; pos--;
			}
		}
		else {
			for (int j = num; j > vt[i + 1].first; j--) {
				ans[pos] = arr[left];
				check[left] = true;
				pos--; left++;
			}
		}
	}
	int num = vt[cnt - 1].first;
	int up = vt[cnt - 1].second;
	if (up) {
		for (int i = right; i >= left; i--) ans[pos--] = arr[i];
	}
	else
		for (int i = left; i <= right; i++) {
			ans[pos--] = arr[i];
		}
	
	for (int i = 0; i <= vt[0].first; i++) printf("%d ", ans[i]);
	for (int i = vt[0].first+1; i < n; i++) printf("%d ", arr[i]);
	puts("");
}