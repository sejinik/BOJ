#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

vector<pair<int, string>> vt;
int arr[51];
int n;
int cnt;

int main() {
	scanf("%d", &n);

	int max_size = 0;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		int size = str.size();
		vt.push_back({ size,str });
		arr[size]++;
		max_size = max(max_size, size);
	}

	sort(vt.begin(), vt.end());
	for (int i = 1; i <= max_size; i++) {
		set<string> s;
		set<string>::iterator st;
		for (int j = 0; j < arr[i]; j++) {
			s.insert(vt[cnt++].second);			
		}

		for (st = s.begin(); st != s.end(); ++st) {
			cout << *st << "\n";
		}
	}
	return 0;
}