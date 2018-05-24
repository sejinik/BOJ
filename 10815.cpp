#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> vt;
int num, que;

int main() {
	scanf("%d", &num);
	vt.resize(num + 1);

	for (int i = 1; i <= num; i++) {
		int temp;
		scanf("%d", &temp);
		vt.push_back(temp);
	}
	sort(vt.begin(), vt.end());
	scanf("%d", &que);

	for (int i = 0; i < que; i++) {
		int score;
		scanf("%d", &score);
		printf("%d ", binary_search(vt.begin(), vt.end(), score));
	}
	printf("\n");
	return 0;
}