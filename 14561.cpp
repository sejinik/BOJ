#include <cstdio>
#include <vector>
using namespace std;

int tcase;

int main() {
	scanf("%d", &tcase);
	while (tcase--) {
		vector<long long> a;
		long long num;
		long long n;
		scanf("%lld %lld", &num, &n);

		while (num >= n) {
			a.push_back(num%n);
			num /= n;
		}
		if(num !=0)
			a.push_back(num);

		int size = a.size();
		bool check = true;
		for (int i = 0; i < size/2; i++) {
			if (a[i] != a[(size-1) - i]) {
				check = false;
				break;
			}
		}
		if (check)
			puts("1");
		else
			puts("0");
	}
	return 0;
}