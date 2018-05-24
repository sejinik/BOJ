#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
char map[6][100];
string str;
int dx[8] = { -2,-1,0,1,2,1,0,-1 };
int dy[8] = { 0,1,2,1,0,-1,-2,-1 };

void change(int y,int cnt) {
	for (int i = 0; i < 8; i++) {
		int nx = 2 + dx[i];
		int ny = y + dy[i];
		if (cnt % 3 == 0) map[nx][ny] = '*';
		else {
			if(map[nx][ny] != '*') map[nx][ny] = '#';
		}
	}
}
int main() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 100; j++) {
			map[i][j] = '.';
		}
	}
	cin >> str;
	int n = str.size();
	int len = n+(4 + (n - 1) * 3);
	for (int i = 0; i < n; i++) {
		map[2][2 + (i * 4)] = str[i];
	}
	
	int cnt = 1;
	for (int i = 0; i < len; i++) {
		if ('A' <= map[2][i] && map[2][i] <= 'Z') change(i, cnt++);
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < len; j++) {
			printf("%c", map[i][j]);
		}
		puts("");
	}
}