#include <iostream>
#include <vector>
using namespace std;

int tcase;
int num;
int ans;

vector<int> tri_num;

void go(int cnt, int sum, int index) {

	if (cnt == 3) {
		if (sum == num) {
			ans++;
		}
		return;
	}

	if (sum > num || index == 50) return;

	//���������ϰ� �ߺ��Ǵ°��
	go(cnt + 1, sum + tri_num[index], index);

	//���������ϰ� �ߺ������ʴ� ���
	go(cnt + 1, sum + tri_num[index], index + 1);

	//�������������ʴ°��
	go(cnt, sum, index + 1);

}

int main() {

	for (int i = 0; i < 50; i++) {
		int temp = ((i+1)*(i + 2)) / 2;
		tri_num.push_back(temp);
	}


	scanf("%d", &tcase);

	while (tcase--) {
		scanf("%d", &num);
		ans = 0;
		go(0, 0, 0);

		if (ans)
			puts("1");
		else
			puts("0");
	}
	return 0;
}