#include <iostream>
#include <algorithm>
using namespace std;
bool check[10010];
int arr[4];

int main() {
	int ans = 1e+9;
	for (int i = 1111; i <= 9999; i++) {
		ans = 1e+9;
		arr[0] = i / 1000;
		arr[1] = (i % 1000) / 100;
		arr[2] = (i % 100) / 10;
		arr[3] = i % 10;
		
		if (arr[0] == 0 || arr[1] == 0 || arr[2] == 0 || arr[3] == 0) continue;
		for (int i = 0; i < 4; i++) {
			int num = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
			ans = min(ans, num);
			int temp = arr[0];
			arr[0] = arr[1];
			arr[1] = arr[2];
			arr[2] = arr[3];
			arr[3] = temp;
		}
		check[ans] = true;
	}

	for (int i = 0; i < 4; i++) scanf("%d", &arr[i]);
	ans = 1e+9;
	for (int i = 0; i < 4; i++) {
		int num = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
		ans = min(ans, num);
		int temp = arr[0];
		arr[0] = arr[1];
		arr[1] = arr[2];
		arr[2] = arr[3];
		arr[3] = temp;
	}
	int cnt = 0;
	for (int i = 1111; i <= ans; i++) {
		if (check[i]) cnt++;
	}
	printf("%d\n", cnt); 
	return 0;
}