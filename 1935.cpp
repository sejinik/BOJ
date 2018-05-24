#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
int n;
string str;
stack<double> st;
double arr[26];
int main() {
	scanf(" %d", &n);
	cin >> str;
	for (int i = 0; i < n; i++) {
		scanf("%lf", &arr[i]);
	}

	int m = str.size();
	double ans = 0;
	for (int i = 0; i < m; i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			double s = arr[str[i] - 'A'];
			st.push(s);
		}
		else {
			double b = st.top();
			st.pop();
			double a = st.top();
			st.pop();

			if (str[i] == '+') ans = a + b;
			if (str[i] == '-') ans = a - b;
			if (str[i] == '*') ans = b*a;
			if (str[i] == '/') ans = a / b;
			st.push(ans);
		}
	}
	printf("%.2lf\n", ans);
	return 0;
}