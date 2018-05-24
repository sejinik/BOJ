#include <cstdio>
#include <algorithm>
using namespace std;
int arr[100010][2];
int n,ans,cnt,pos;

int main() {
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) scanf(" %d %d", &arr[i][0], &arr[i][1]);
	for (int i = 1; i <= 5; i++) {
		cnt = 0;
		for (int j = 0; j < n; j++) {
			if (arr[j][0] == i || arr[j][1]== i) cnt++;
			if (ans < cnt) {
				ans = cnt;
				pos = i;
			}
			if (arr[j][0] != i && arr[j][1] != i) cnt = 0;
		}
	}
	printf("%d %d\n", ans, pos);
}