#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int n, arr[3] = { 7,7,7 }, ans, h, cnt;
bool bf[3], af[3];
int main() {
	priority_queue<pair<int, pair<int, int>>> pq;
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) {
		int a, d, z; string c;
		cin >> a >> c >> d;
		if (c == "Bessie") z = 0;
		else if (c == "Elsie")	 z = 1;
		else z = 2;
		pq.push({ -a,{ z,d } });
	}
	h = 7, cnt = 3;
	for (int i = 0; i < 3; i++) bf[i] = true;
	while (!pq.empty()) {
		int pos = pq.top().second.first;
		int cost = pq.top().second.second;
		pq.pop();
		arr[pos] += cost;
		int temp = max({ arr[0],arr[1],arr[2] });
		for (int i = 0; i < 3; i++) if (temp == arr[i]) af[i] = true;
		for (int i = 0; i < 3; i++) if (bf[i] != af[i]) { ans++; break; }
		for (int i = 0; i < 3; i++) bf[i] = af[i], af[i] = false;
	}
	printf("%d\n", ans);
}