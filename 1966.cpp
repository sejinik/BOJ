#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int arr[110];
int cnt;

int main() {
	int Tcase;
	scanf("%d", &Tcase);

	while (Tcase--) {
		int num, location;
		queue<pair<int, int>> q;

		scanf("%d %d", &num, &location);
		
		for (int i = 0; i < num; i++) {
			int con;
			scanf("%d", &con);
			q.push(make_pair(i, con));
			arr[i] = con;
		}

		sort(arr, arr + num);
		reverse(arr, arr + num);

		cnt = 0;

		while(1){
			if (arr[cnt] == q.front().second) {
				arr[cnt] = 0;
				cnt++;
				if (q.front().first == location) {
					printf("%d\n", cnt);
					break;
				}
			}
			q.push(q.front());
			q.pop();
		}
	}
}