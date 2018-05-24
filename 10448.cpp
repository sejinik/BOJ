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

	//나를포함하고 중복되는경우
	go(cnt + 1, sum + tri_num[index], index);

	//나를포함하고 중복되지않는 경우
	go(cnt + 1, sum + tri_num[index], index + 1);

	//나를포함하지않는경우
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