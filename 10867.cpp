#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s;
	int num,a;
	scanf("%d", &num);
	while (num--) {
		scanf("%d", &a);
		s.insert(a);
	}

	for (set<int>::iterator i = s.begin(); i != s.end(); i++) {
		printf("%d ", *i);
	}
	return 0;
}