#include <iostream>
#include <vector>
using namespace std;

vector<int> vt;

void go(vector<int> &a, int index, int cnt) {

	if (cnt == 6) {
		for (int i = 0; i < vt.size(); i++) {
			printf("%d ", vt[i]);
		}
		printf("\n");
		return;
	}

	if (index == a.size()) return;

	//�ڱⲨ ���°��   <- ���ļ� ��¿��ϹǷ� �ڱⲨ ���� ������
	vt.push_back(a[index]);
	go(a, index + 1, cnt + 1);
	vt.pop_back();

	//�ڱⲨ �ǳʶٰ� �����ź��°��
	go(a, index + 1, cnt);
}

int main() {
	while (1) {
		int num;
		scanf("%d", &num);
		if (num == 0) return 0;

		vector<int> a(num);
		for (int i = 0; i < num; i++) {
			scanf("%d", &a[i]);
		}

		go(a, 0, 0);
		printf("\n");
	}
	return 0;
}