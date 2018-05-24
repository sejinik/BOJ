#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;
int t;
int main() {
	scanf("%d", &t);
	while (t--) {
		deque<int> dq;
		string str,num;
		int n;
		cin >> str;
		scanf(" %d", &n);
		cin >> num;
		int cnt = 0;
		for (int i = 0; i < num.size()-1; i++) {
			if (num[i] == '[' || num[i] == ',' || num[i] == ']') continue;
			cnt += num[i] - '0';
			if (num[i + 1] == ',' || num[i+1] == ']') {
				dq.push_back(cnt); cnt = 0;
			}
			else cnt *= 10;
		}
		bool pos = true;
		bool error = false;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'R') pos = !pos;
			else {
				if (dq.empty()) {
					error = true; break;
				}
				else {
					if (pos) dq.pop_front();
					else dq.pop_back();
				}
			}
		}
		if (error) puts("error");
		else {
			if (!pos) reverse(dq.begin(), dq.end());
			printf("[");
			for (int i = 0; i < dq.size(); i++) {
				if (i != 0) printf(",");
				printf("%d", dq[i]);
			}
			printf("]\n");
		}
	}
}