#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool check[202][202];
bool ans[202];
int A, B, C;
int sum;

void bfs(int _x, int _y) {
	queue<pair<int, int>> q;
	check[_x][_y] = true;
	ans[sum - _x - _y] = true;
	q.push({ _x,_y });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int z = sum - x - y;
		q.pop();

		int nx = x, ny = y, nz = z;
		//x ->y
		ny += nx; 
		nx = 0;

		if (ny >= B) {
			nx = ny - B;
			ny = B;
		}

		if (!check[nx][ny]) {
			check[nx][ny] = true;
			q.push({ nx,ny });

			if (nx == 0) {
				ans[nz] = true;
			}
			
		}
		//x ->z
		nx = x, ny = y, nz = z;
		nz += nx;
		nx = 0;

		if (nz >= C) {
			nx = nz - C;
			nz = C;
		}

		if (!check[nx][ny]) {
			check[nx][ny] = true;
			q.push({ nx,ny });

			if (nx == 0) {
				ans[nz] = true;
			}
		}
		//y ->x
		nx = x, ny = y, nz = z;
		nx += ny;
		ny = 0;

		if (nx >= A) {
			ny = nx - A;
			nx = A;
		}

		if (!check[nx][ny]) {
			check[nx][ny] = true;
			q.push({ nx,ny });

			if (nx == 0) {
				ans[nz] = true;
			}
		}

		//y ->z
		nx = x, ny = y, nz = z;
		nz += ny;
		ny = 0;

		if (nz >= C) {
			ny = nz - C;
			nz = C;
		}

		if (!check[nx][ny]) {
			check[nx][ny] = true;
			q.push({ nx,ny });

			if (nx == 0)
				ans[nz] = true;
		}
		//z ->x
		nx = x, ny = y, nz = z;
		nx += nz;
		nz = 0;

		if (nx >= A) {
			nz = nx - A;
			nx = A;
		}

		if (!check[nx][ny]) {
			check[nx][ny] = true;
			q.push({ nx,ny });

			if (nx == 0)
				ans[nz] = true;
		}
		//z ->y
		nx = x, ny = y, nz = z;
		ny += nz;
		nz = 0;

		if (ny >= B) {
			nz = ny - B;
			ny = B;
		}

		if (!check[nx][ny]) {
			check[nx][ny] = true;
			q.push({ nx,ny });

			if (nx == 0)
				ans[nz] = true;
		}
	}
}

int main() {
	scanf("%d%d%d", &A, &B, &C);
	sum = C;
	bfs(0, 0);
	for (int i = 0; i <= 200; i++)
		if (ans[i])
			printf("%d ", i);
	printf("\n");

	return 0;
}