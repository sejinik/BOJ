#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
int n, m;
map<int, string> num;
map<string, int> name;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		char a[22];
		scanf(" %s", a);
		num[i + 1] = a;
		name[a] = i+1;
	}
	for (int i = 0; i < m; i++) {
		char a[22];
		scanf(" %s", a);
		if ('0' <a[0]&& a[0] <= '9') {
			string s = a;
			int temp = stoi(s);
			cout << num[temp] << "\n";
		}
		else {
			printf("%d\n", name[a]);
		}
	}
	return 0;
}