#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> vt[1001000];
bool check[1001000];
long long d[1001000];
int cnt;
int abc;

void dfs(int here) {
	
		int there = vt[here][0];

		if (check[there] == false)
			check[there] = true;
		else
			abc = there;
	
}

int main() {
	int A, P;
	scanf("%d %d", &A, &P);
	d[1] = A;
	vt[1].push_back(A);

	for (int i = 2; i <= 10000; i++) {
		int score = d[i - 1];
		while (score != 0) {
			d[i] += pow(score % 10, P);
			score /= 10;
		}
		vt[i].push_back(d[i]);
	}

	for (int i = 1; i <= 10000; i++) {
		if (check[i] == false) {
			dfs(i);
		}
		if (abc != 0)
			break;
	}

	for (int i = 1; i <= 10000; i++) {
		if (d[i] != abc)
			cnt++;
		if (d[i] == abc)
			break;
	}
	printf("%d\n", cnt);
	
	return 0;
}