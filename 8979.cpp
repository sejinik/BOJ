#include <iostream>
using namespace std;

int arr[1001][4];
int RANK[1001];
int cnt;


int main() {

	int nation, want;
	scanf("%d %d", &nation, &want);

	for (int i = 1; i <= nation; i++) {
		scanf("%d %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3]);
	}

	for (int i = 1; i <= nation; i++) {
		cnt = 0;
		for (int j = 1; j <= nation; j++) {
			if (i == j) continue;
			for (int k = 1; k < 4; k++) {
				if (arr[i][k] > arr[j][k])
					break;

				else if (arr[i][k] < arr[j][k]) {
					cnt++;
					break;
				}
			}
		}
		RANK[arr[i][0]] = cnt + 1;
	}
	printf("%d\n", RANK[want]);
	return 0;
}