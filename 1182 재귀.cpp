#include <iostream>
#include <vector>
using namespace std;

vector<int> vt;
int N, S;

int ans;

void go(int index, int sum) {

	if (index == N) {
		if (sum == S) {
			ans++;
		}
		return;
	}

	go(index + 1, sum + vt[index]);
	go(index + 1, sum);

}

int main() {
	scanf("%d%d", &N, &S);
	vt.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &vt[i]);
	}

	go(0, 0);
	if (S == 0)
		ans--;

	printf("%d\n", ans);
	return 0;
}