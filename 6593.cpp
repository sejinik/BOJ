#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int inf = 100000000;
int l, r, c;
int from_x, from_y, from_z;
int to_x, to_y, to_z;
int arr[33][33][33];
int dist[33][33][33];
int dx[6] = { 0,0,0,0,1,-1 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 1,-1,0,0,0,0 };
int main() {
	while (scanf("%d %d %d", &l, &r, &c)) {
		if (l == 0 && r == 0 && c == 0) return 0;
		memset(dist, -1, sizeof(dist));
		memset(arr, 0, sizeof(arr));
		bool check_s = false;
		bool check_e = false;
		for (int k = 0; k < l; k++) {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					char temp;
					scanf(" %1c", &temp);
					arr[i][j][k] = 1;
					if (temp == '#') arr[i][j][k] = inf;
					if (temp == 'S') {
						check_s = true;
						from_x = i, from_y = j, from_z = k;
					}
					if (temp == 'E') {
						check_e = true;
						to_x = i, to_y = j, to_z = k;
					}
					
				}
			}
			string str1, str2;
			getline(cin, str1);
			getline(cin, str2);
		}
		priority_queue < pair<int, pair<int, pair<int, int>>>> pq;
		pq.push({ 0,{from_x,{from_y,from_z}} });
		while (!pq.empty()) {
			int x = pq.top().second.first;
			int y = pq.top().second.second.first;
			int z = pq.top().second.second.second;
			int cost = -pq.top().first;
			pq.pop();
			if (dist[x][y][z] != -1) continue;
			dist[x][y][z] = cost;
			if(dist[to_x][to_y][to_z] != -1) break;
			for (int i = 0; i < 6; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nz = z + dz[i];
				int ncost = -cost - arr[nx][ny][nz];
				if (0 <= nx && nx < r && 0 <= ny && ny < c && 0 <= nz && nz < l) {
					if (dist[nx][ny][nz] == -1 && arr[nx][ny][nz] != inf) pq.push({ ncost,{nx,{ny,nz}} });
				}
			}
		}
		if (check_s == true && check_e == true) {
			if (dist[to_x][to_y][to_z] == -1) puts("Trapped!");
			else printf("Escaped in %d minute(s).\n", dist[to_x][to_y][to_z]);
		}
		else puts("Trapped!");
	}
}