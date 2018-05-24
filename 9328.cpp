#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int t, n, m;
char map[111][111];
bool check[111][111];
bool key[111];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main() {
	scanf(" %d", &t);
	while (t--) {
		memset(map, 0, sizeof(map));
		memset(check, 0, sizeof(check));
		memset(key, 0, sizeof(key));
		scanf(" %d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf(" %1c", &map[i][j]);
			}
		}

		string s; cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0') continue;
			key[s[i] - 'a'] = true;
		}
		int ans = 0;
		queue<pair<int, int>> q;
		queue<pair<int, int>> door[26];
		q.push({ 0,0 }); check[0][0] = true;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx <= n + 1 && 0 <= ny && ny <= m + 1) {
					if (map[nx][ny] == '*' || check[nx][ny]) continue;
					check[nx][ny] = true;
					if ('A' <= map[nx][ny] && map[nx][ny] <= 'Z') {
						if (key[map[nx][ny] - 'A']) q.push({ nx,ny });
						else door[map[nx][ny] - 'A'].push({ nx,ny });
					}
					else if ('a' <= map[nx][ny] && map[nx][ny] <= 'z') {
						q.push({ nx,ny });
						if (!key[map[nx][ny] - 'a']) {
							key[map[nx][ny] - 'a'] = true;
							while (!door[map[nx][ny] - 'a'].empty()) {
								q.push({ door[map[nx][ny] - 'a'].front() });
								door[map[nx][ny] - 'a'].pop();
							}
						}
					}
					else {
						q.push({ nx,ny });
						if (map[nx][ny] == '$') ans++;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
}