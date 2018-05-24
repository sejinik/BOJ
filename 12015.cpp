#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> vt;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		auto pos = lower_bound(vt.begin(), vt.end(), num);
		if (pos == vt.end())
			vt.push_back(num);
		else
			*pos = num;
	}

	cout << vt.size() << endl;
	return 0;
}