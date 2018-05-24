#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int n;
set<int> s;

int main() {
	scanf("%d", &n);

	int ans = 0;
	for (int i = 0; i < n*2; i++) {
		int num;
		scanf("%d", &num);
		if (s.count(num))
			s.erase(num);
		else
			s.insert(num);

		int size = s.size();
		ans = max(ans, size);
	}
	printf("%d\n", ans);
	return 0;
			
}