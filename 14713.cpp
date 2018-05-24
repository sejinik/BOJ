#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
queue<string> q[111];
string arr[111];
int n;

int main() {
	scanf("%d ", &n);
	for (int i = 0; i < n; i++) {
		getline(cin, arr[i]);

		int m = arr[i].size();
		string temp = "";
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != ' ') temp += arr[i][j];
			else {
				q[i].push(temp);
				temp = "";
			}
		}
		q[i].push(temp);
	}

	string l;
	getline(cin, l);
	int m = l.size();
	string temp = "";
	for (int i = 0; i < m; i++) {
		if (l[i] != ' ') temp += l[i];
		else {
			bool check = false;
			for (int j = 0; j < n; j++) {
				if (q[j].front() == temp) {
					check = true;
					q[j].pop(); temp = "";
					break;
				}
			}
			if (!check) {
				puts("Impossible");
				return 0;
			}
		}
	}

	bool check = false;
	for (int i = 0; i < n; i++) {
		if (q[i].front() == temp) {
			check = true;
			q[i].pop();
			for (int j = 0; j < n; j++) {
				if (!q[j].empty()) {
					puts("Impossible");
					return 0;
				}
			}
		}
	}
	if (check) puts("Possible");
	else puts("Impossible");
	return 0;
}