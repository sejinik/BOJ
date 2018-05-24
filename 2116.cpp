#include <iostream>
#include<algorithm>
using namespace std;
int n,ans;
int arr[10010][6];
int nxt(int x) {
	if (x == 0 || x == 5) return 5 - x;
	else if (x == 1 || x == 2) return x + 2;
	else return x - 2;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			scanf(" %d", &arr[i][j]);
		}
	}
	
	for (int i = 0; i < 6; i++) {
		int pos = i;
		int pos_value = arr[0][pos];
		int next = nxt(pos);
		int next_value = arr[0][next];
		int c = 0;
		for (int j = 0; j < n; j++) {
			int temp = 0;
			for (int k = 0; k < 6; k++)
				if (arr[j][k] == pos_value) pos = k, next = nxt(pos);
			next_value = arr[j][next];
			for (int k = 0; k < 6; k++) {
				if (arr[j][k] == pos_value || arr[j][k] == next_value) continue;
				temp = max(temp, arr[j][k]);
			}
			c += temp;
			pos_value = next_value;
		}
		ans = max(ans, c);
	}
	printf("%d\n", ans);
}