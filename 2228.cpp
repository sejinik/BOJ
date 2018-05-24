#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF -1e+9
#define MIN -999999
int arr[111];
int psum[111];
int d[111][111];
int n, m;

int go(int pos, int cnt) {
	if (cnt == 0) return 0;
	if (pos <= 0) return MIN;
	int&ret = d[pos][cnt];
	if (ret != INF) return ret;
	//추가하지 않는 경우
	ret = go(pos - 1, cnt);
	//추가하는 경우
	for (int i = pos; i > 0; i--) {
		int temp = go(i - 2, cnt - 1) + psum[pos] - psum[i - 1];
		ret = max(ret, temp);
	}
	return ret;
}
int main() {
	for (int i = 0; i < 111; i++) 
		for (int j = 0; j < 111; j++) d[i][j] = INF;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		if(i==1) psum[1] = arr[1];
		else psum[i] = psum[i - 1] + arr[i];
	}
	printf("%d\n", go(n, m));
	return 0;
}