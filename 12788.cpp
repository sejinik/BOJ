#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int M, K;
int num;

vector<int> vt;

int main() {
	scanf("%d", &N);
	scanf("%d%d", &M, &K);
	num = M*K;

	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		vt.push_back(temp);
	}

	sort(vt.begin(), vt.end());
	reverse(vt.begin(), vt.end());

	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += vt[i];
		if (sum >= num) {
			printf("%d\n", i + 1);
			return 0;
		}
	}
	puts("STRESS");
	return 0;
	
}