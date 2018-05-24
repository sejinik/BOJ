#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
string str, bomb;
stack<char> st;
int main() {
	cin >> str >> bomb;
	int l = str.size();
	int bl = bomb.size();

	for (int i = 0; i < l; i++) {
		st.push(str[i]);
		if (st.top() == bomb[bl - 1]) {
			string temp = "";
			bool empty = false;
			for (int i = 0; i < bl; i++) {
				temp += st.top();
				st.pop();
				if (st.empty()) break;
			}
			reverse(temp.begin(), temp.end());
			if (temp == bomb) continue;
			for (int i = 0; i < temp.size(); i++)
				st.push(temp[i]);
		}
	}
	if (!st.size()) puts("FRULA");
	else {
		string ans = "";
		while (!st.empty()) {
			ans += st.top();
			st.pop();
		}
		reverse(ans.begin(), ans.end());
		cout << ans << "\n";
	}
	return 0;
}