#include <iostream>
using namespace std;
int arr[101];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int sum = 0;
	int point = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 1) {
			point += 1;
			sum += point;
		}
		else point = 0;
	}
	cout << sum << "\n";
	return 0;
}