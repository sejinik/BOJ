#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int arr[3];
vector<pair<char, int>> vt;
int main() {
	for (int i = 0; i < 3; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + 3);
	vt.push_back({ 'A',arr[0] });
	vt.push_back({ 'B',arr[1] });
	vt.push_back({ 'C',arr[2] });
	string str;
	cin >> str;
	int l = str.size();
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < 3; j++) {
			if (vt[j].first == str[i]) {
				printf("%d ", vt[j].second);
				break;
			}
		}
	}
	printf("\n");
	return 0;
}