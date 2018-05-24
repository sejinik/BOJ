#include <iostream>	
#include <algorithm>
#include <string>
using namespace std;
int n, m;
char map[20][20];
int d[14 * 14 + 1][(1 << 14)];
int score[6][6] = { { 10,8,7,5,0,1 },
{ 8,6,4,3,0,1 },
{ 7,4,3,2,0,1 },
{ 5,3,2,2,0,1 },
{ 0,0,0,0,0,0 },
{ 1,1,1,1,0,0 } };
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf(" %s", &map[i]);
	}

	for (int i = 0; i < n*m; i++) {
		for (int j = 0; j < (1 << m); j++) {
			d[i + 1][j >> 1] = max(d[i + 1][j >> 1], d[i][j]);
			if (!(j & 1))
				d[i + 1][(j >> 1) + (1 << (m - 1))] = max({ d[i][j], d[i + 1][(j >> 1) + (1 << (m - 1))], d[i][j] + score[map[i / m][i%m] - 'A'][map[(i / m) + 1][(i%m)] - 'A'] });
			if (!(j & 3) && ((i%m) != (m - 1)))
				d[i + 1][(j >> 1) + 1] = max({ d[i][j],d[i + 1][(j >> 1) + 1],d[i][j] + score[map[i / m][i%m] - 'A'][map[i / m][(i%m) + 1] - 'A'] });
		}
	}
	printf("%d\n", d[n*m][0]);
	return 0;
}