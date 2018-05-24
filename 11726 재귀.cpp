#include <iostream>
#include <cstring>
using namespace std;

int dp[1010];

int func(int num) {

	//기저사례
	if (num == 1) return 1;
	if (num == 2) return 2;
	
	// 이미 계산된 식
	int& ret = dp[num];
	if (ret != -1) return ret;
	
	//점화식
	ret = func(num - 1) % 10007 + func(num - 2) % 10007;

	// 값 리턴
	return ret % 10007;
}

int main() {
	memset(dp, -1, sizeof(dp));
	int num;
	scanf("%d", &num);

	printf("%d\n", func(num));
}