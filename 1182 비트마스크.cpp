#include <iostream>
#include <vector>
using namespace std;

int N, S;
int cnt;

int main() {
	scanf("%d%d", &N, &S);
	vector<int> vt(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &vt[i]);
	}

	for (int i = 1; i < (1 << N); i++) {
		int sum = 0;
		for (int k = 0; k < N; k++) {
			if (i & (1<< k)) {
				sum += vt[k];
			}
		}

		if (sum == S) {
			cnt++;
		}

	}
	printf("%d\n", cnt);
	return 0;
}