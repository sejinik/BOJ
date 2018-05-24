#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vt;

int main() {
	int num;
	scanf("%d", &num);
	
	for (int i = 0; i < num; i++) {
		int a;
		scanf("%d", &a);
		vt.push_back(a);
	}
	sort(vt.begin(), vt.end());
	for (int i = 0; i < vt.size(); i++) {
		printf("%d\n", vt[i]);
	}
	return 0;
}