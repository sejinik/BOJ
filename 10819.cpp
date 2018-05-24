#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int sum;

int main() {
	int num;
	scanf("%d", &num);

	vector<int> vt;

	for (int i = 0; i < num; i++) {
		int temp;
		scanf("%d", &temp);
		vt.push_back(temp);
	}

	sort(vt.begin(), vt.end());

	do {
		int temp = 0;
		for (int i = 0; i < vt.size()-1; i++) {
			temp += abs(vt[i] - vt[i + 1]);
		}
		sum = max(sum, temp);
	} while (next_permutation(vt.begin(), vt.end()));

	printf("%d\n", sum);
	return 0;

}