﻿#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
int n;
int arr[100010];
stack<int> st;
vector<char> ans;

int main() {
	int it = 1;
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf(" %d", &x);
		if (st.empty() || st.top() != x) {
			while (true) {
				if (it > n) {
					puts("NO"); return 0;
				}
				st.push(it++);
				ans.push_back('+');
				if (st.top() == x) {
					st.pop();
					ans.push_back('-'); break;
				}
			}
		}
		else if (st.top() == x) {
			st.pop(); ans.push_back('-');
		}
	}
	for (int i = 0; i < ans.size(); i++) printf("%c\n", ans[i]);
}