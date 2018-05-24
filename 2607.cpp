#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int n,cnt=1;
int arr[111][26];
string str[111];

int main() {
	scanf("%d", &n);
	string fir;
	cin >> fir;
	int fs = fir.size();
	for (int i = 0; i < fs; i++) arr[0][fir[i] - 'A']++;
	for (int i = 0; i < n-1; i++) {
		string temp; 
		cin >> temp;
		int ts = temp.size();
		if (abs(fs - ts) >= 2) continue;
		for (int j = 0; j < ts; j++) arr[cnt][temp[j] - 'A']++;
		cnt += 1;
	}
	
	int ans = 0;
	for (int i = 1; i < cnt; i++) {
		bool check = true;
		bool fp=true, fm = true;
		bool sp = true, sm = true;
		int go = 0;
		for (int j = 0; j < 26; j++) {
			if (arr[0][j] != arr[i][j]) {
				if (abs(arr[0][j] - arr[i][j]) >= 2) {
					check = false; break;
				}
				else {
					if (go == 0) {
						if (arr[0][j] > arr[i][j]) fm = false;
						else fp = false;
					}
					else if (go == 1) {
						if (arr[0][j] > arr[i][j]) sm = false;
						else sp = false;
						if ((fm == sm) || (fp == sp)) {
							check = false; break;
						}
					}
					go += 1;
				}
			}
		}
		if (check && go < 3) ans += 1;
	}
	printf("%d\n", ans);
}