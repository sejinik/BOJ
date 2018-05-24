#include <iostream>
using namespace std;

int p[1010];
int pn;
bool c[1010];

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	for (int i = 2; i <= N; i++) {
		if (c[i] == false)
			p[pn++] = i;
		for (int j = i*2; j <= N; j+=i) {
			if(c[j] == false)
				p[pn++] = j;
			c[j] = true;
		}
	}
	int ans = p[K - 1];
	printf("%d\n", ans);
	return 0;
}