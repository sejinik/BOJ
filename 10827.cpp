#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
bool check;
void nomalize(vector<int>& c) {
	c.push_back(0);
	for (int i = 0; i < c.size(); i++) {
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	if(!check)
		while (c.size() > 1 && c.back() == 0) c.pop_back();
}
vector<int> multiply(vector<int>&a, vector<int>& b) {
	vector<int> c(a.size() + b.size() + 1,0);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			c[i + j] += a[i] * b[j];
		}
	}
	nomalize(c);
	return c;
}
int main() {
	string str;
	int n;
	cin >> str >> n;
	int m = str.size();
	vector<int> vt;
	if (str[0] == '0') check = true;
	int pos = 0;
	for (int i = 0; i < m; i++) {
		if (str[i] == '.') pos = i+1;
		else {
			int num = str[i] - '0';
			vt.push_back(num);
		}
	}
	reverse(vt.begin(), vt.end());
	pos = m - pos;
	pos *= n;

	vector<int> ans = vt;
	n--;
	while (n--) {
		ans = multiply(ans, vt);
	}

	if (check)
		while (ans.size() != pos + 1 && ans.back() == 0) ans.pop_back();
	
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		if (ans.size() - i == pos) printf(".");
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}