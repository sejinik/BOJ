//map, bfs이용해서 완탐!
#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;
int arr[3][3];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int ans = stoi("123456789");
map<int, int> mp;
int main() {
	string arrs = "";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf(" %d", &arr[i][j]);
			if (arr[i][j] == 0) arr[i][j] = 9;
			arrs += (char)arr[i][j] + '0';
		}
	}
	int st = stoi(arrs);
	queue<int> q; q.push(st);
	mp[st] = 0;
	while (!q.empty()) {
		int here = q.front();
		if (here == ans) break;
		q.pop();
		string s = to_string(here);
		int z = s.find('9');
		int x = z / 3, y = z % 3;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < 3 && 0 <= ny && ny< 3) {
				string next = s;
				swap(next[z], next[nx * 3 + ny]);
				int nc = stoi(next);
				if (!mp.count(nc)) {
					mp[nc] = mp[here] + 1;
					q.push(nc);
				}
			}
		}
	}
	if (mp.count(ans)) printf("%d\n", mp[ans]);
	else puts("-1");
}