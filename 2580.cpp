#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int board[9][9];

bool check(int x, int y, int num) {

	bool ret = true;
	for (int i = x + 1; i < 9; i++)
		if (board[i][y] == num)
			ret = false;

	for (int i = x - 1; i >= 0; i--)
		if (board[i][y] == num)
			ret = false;

	for (int i = y + 1; i < 9; i++)
		if (board[x][i] == num)
			ret = false;
	
	for (int i = y - 1; i >= 0; i--)
		if (board[x][i] == num)
			ret = false;

	if (ret == false)
		return false;

	int row, col;
	if (x % 3 == 0) row = x;
	else row = x - (x % 3);

	if (y % 3 == 0) col = y;
	else col = y - (y % 3);

	for (int i = row; i < row + 3; i++) {
		for (int j = col; j < col + 3; j++) {
			if (i == x && j == y) continue;

			if (board[i][j] == num )
				return false;
		}
	}

	return true;
}

void go(vector<pair<int,int>> &a,int index) {

		bool ans = true;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == 0)
					ans  = false;
			}
		}

		if (ans) {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					printf("%d ", board[i][j]);
				}
				printf("\n");
			}
			exit(0);
		}
	


	int x = a[index].first;
	int y = a[index].second;

	for (int i = 1; i < 10; i++) {
		board[x][y] = i;
		if (check(x,y,i) == true) {
			go(a,index + 1);
		}
		board[x][y] = 0;
	}
}

int main() {
	vector<pair<int, int>> vt;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &board[i][j]);

			if (board[i][j] == 0) {
				vt.push_back({ i,j });
			}
		}
	}

	go(vt,0);

	return 0;
}