#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
	string str1, str2;
	cin >> str1 >> str2;

	long long num1=0, num2=0;

	int cnt = 0;
	for (int i = str1.size()-1; i >= 0 ; i--) {
		cnt++;
		if (str1[i] == '1')
			num1 += pow(2, cnt-1);
	}

	cnt = 0;
	for (int i = str2.size()-1; i >= 0; i--) {
		cnt++;
		if (str2[i] == '1')
			num2 += pow(2, cnt-1);
	}
	long long ans = num1*num2;

	stack<int> st;
	while (ans >= 2) {
		st.push(ans % 2);
		ans /= 2;
	}
	st.push(ans);

	while (!st.empty()) {
		printf("%d", st.top());
		st.pop();
	}
	printf("\n");
	return 0;
}