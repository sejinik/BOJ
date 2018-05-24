#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string str1, str2;
int ans = 987654321;

void go(string &s1, string &s2,int start) {
	

	int temp = 0;
	for (int i = start; i < s1.size(); i++) {
		if (s1[i] != s2[i]) {
			temp += 1;
		}
	}
	ans = min(ans, temp);

	if (s1.size() == s2.size()) return;

	s1 = " " + s1;
	go(s1, s2,start+1);

}
int main() {
	cin >> str1 >> str2;

	go(str1,str2,0);

	printf("%d\n", ans);
}