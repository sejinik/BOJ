#include <iostream>
#include <cstdio>
#include <set>
#include <string>
using namespace std;

int main()
{
	set<int> intSet;
	char a[20];
	int num, X;
	scanf("%d", &num);

	while (num--) {
		scanf("%s", a);

		if (a[0] == 'a' && a[1] == 'd') {
			scanf("%d", &X);
			intSet.insert(X);
		}
		else if (a[0] == 'r') {
			scanf("%d", &X);
			intSet.erase(X);
		}
		else if (a[0]== 'c') {
			scanf("%d", &X);
			if (intSet.find(X) != intSet.end())
				printf("%d\n", 1);
			else
				printf("%d\n", 0);
		}
		else if (a[0] == 't') {
			scanf("%d", &X);
			if (intSet.find(X) != intSet.end())
				intSet.erase(X);
			else
				intSet.insert(X);
		}
		else if (a[0] == 'a' && a[1] == 'l') {
			for (int i = 1; i <= 20; i++)
				intSet.insert(i);
		}
		else if (a[0] == 'e') {
			intSet.clear();
		}
	}
	return 0;
}
