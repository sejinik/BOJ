#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int t;
string str, ans;
stack<char> q;
stack<char> st;

int main() {
	scanf("%d", &t);
	while (t--) {
		cin >> str;
		int m = str.size();
		for (int i = 0; i < m; i++) {
			if (str[i] == '<') {
				if (st.empty()) continue;
				else {
					q.push(st.top()); st.pop();
				}
			}
			else if (str[i] == '>') {
				if (q.empty()) continue;
				else {
					st.push(q.top()); q.pop();
				}
			}
			else if (str[i] == '-') {
				if (!st.empty()) st.pop();
			}
			else {
				st.push(str[i]);
			}
		}
		while (!q.empty()) {
			st.push(q.top()); q.pop();
		}
		ans = "";
		while (!st.empty()) {
			ans += st.top(); st.pop();
		}
		reverse(ans.begin(), ans.end());
		cout << ans << "\n";
	}
	return 0;
}