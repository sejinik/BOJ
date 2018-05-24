#include <iostream>
#include <stack>
#include <string>
using namespace std;
string str;
stack<char> st;

int main() {
	cin >> str;
	int l = str.size();
	for (int i = 0; i < l; i++) {
		if (str[i] == '(') st.push(str[i]);
		else {
			char a=' ';
			if (!st.empty()) a = st.top();
			if (a == '(') st.pop();
			else st.push(str[i]);
		}
	}
	cout << st.size() << "\n";
	return 0;
}