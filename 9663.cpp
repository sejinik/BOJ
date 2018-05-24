#include <iostream>
#include <algorithm>
using namespace std;

int N;

bool board[20][20];
int ans;

bool check(int row, int col) {
	
	for (int i = 1; i < N; i++) {
		if (row - i < 0) continue;
		if (board[row - i][col])
			return false;
	}

	for (int i = 1; i < N; i++) {
		if (col - i < 0) continue;
		if (row - i < 0) continue;
		if (board[row - i][col - i])
			return false;
	}
	
	for (int i = 1; i < N; i++) {
		if (col + i >= N) continue;
		if (row - i < 0) continue;
		if (board[row - i][col + i])
			return false;
	}
	return true;
}

void go(int row) {

	if (row == N) {
		ans++;
		return;
	}

	for (int i = 0; i < N; i++) {
		board[row][i] = true;
		if (check(row,i) == true) {
			go(row + 1);
		}
		board[row][i] = false;
	}
}

int main() {
	scanf("%d", &N);
	
	go(0);
	printf("%d\n", ans);
	return 0;

}