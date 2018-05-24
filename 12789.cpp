#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	stack<int> s;
	queue<int> q;

	int num, k;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &k);
		q.push(k);
	}

	for (int i = 1; i <= num; i++) {
		for (int j = 0; j < num; j++) {
			if (!s.empty() && s.top() == i) {
				s.pop();
				break;
			}
			else if (!q.empty() && q.front() == i) {
				q.pop();
				break;
			}
			else {
				if (!q.empty()) {
					s.push(q.front());
					q.pop();
				}
			}
		}
	}
	if (q.empty() && s.empty())
		printf("Nice\n");
	else
		printf("Sad\n");
	return 0;

}