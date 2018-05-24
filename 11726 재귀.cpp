#include <iostream>
#include <cstring>
using namespace std;

int dp[1010];

int func(int num) {

	//�������
	if (num == 1) return 1;
	if (num == 2) return 2;
	
	// �̹� ���� ��
	int& ret = dp[num];
	if (ret != -1) return ret;
	
	//��ȭ��
	ret = func(num - 1) % 10007 + func(num - 2) % 10007;

	// �� ����
	return ret % 10007;
}

int main() {
	memset(dp, -1, sizeof(dp));
	int num;
	scanf("%d", &num);

	printf("%d\n", func(num));
}