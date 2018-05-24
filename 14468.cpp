#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int timer=1;
int arr[26];

int main() {
	memset(arr, -1, sizeof(arr));
	string str;
	cin >> str;
	int s = str.size();

	int cnt = 0;
	for (int i = 0; i < s; i++) {
		int num = str[i] - 'A';
		if (arr[num] == -1) {
			arr[num] = timer++;
		}
		else {
			for (int i = 0; i < 26; i++) {
				if (arr[i] != -1 && i != num) {
					if (arr[num] < arr[i]) {
						cnt += 1;
					}
				}
			}
			arr[num] = -1;
		}
	}
	printf("%d\n", cnt);
	return 0;
}