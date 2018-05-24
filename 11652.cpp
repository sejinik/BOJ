#include <iostream>
#include <map>
using namespace std;

int main() {
	int num;
	scanf("%d", &num);
	
	map<long long, int> mp;

	while (num--) {
		long long a;
		scanf("%lld", &a);
		mp[a] += 1;
	}

	map<long long, int>::iterator it;
	long long ans = 0;
	int cnt = 0;
	for (it = mp.begin(); it != mp.end(); ++it) {
		if (it->second > cnt) {
			cnt = it->second;
			ans = it->first;
		}
		else if (it->second == cnt && it->first < ans) {
			ans = it->first;
		}
	}
	printf("%lld\n", ans);
	return 0;
}