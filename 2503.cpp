#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[3];
int temp[3];
int ans;
int check[1000];

int main() {
	scanf("%d", &N);

	
	for (int i = 0; i < N; i++) {
		int num, s, b;

		scanf("%d %d %d", &num, &s, &b);
	
		arr[0] = num % 10;
		arr[1] = (num / 10) % 10;
		arr[2] = num / 100;


		for (int i = 123; i <= 987; i++) {

			int strike = 0;
			int ball = 0;

			temp[0] = i % 10;
			temp[1] = (i / 10) % 10;
			temp[2] = i / 100;


			if (temp[0] == temp[1] || temp[1] == temp[2] || temp[2] == temp[0]) continue;
			if (temp[0] == 0 || temp[1] == 0 || temp[2] == 0) continue;


			for (int i = 0; i < 3; i++) {
				if (arr[i] == temp[i])
					strike++;
			}
			
			if (arr[0] == temp[1] || arr[0] == temp[2])
				ball++;
			if (arr[1] == temp[0] || arr[1] == temp[2])
				ball++;
			if (arr[2] == temp[0] || arr[2] == temp[1])
				ball++;

			if (s == strike && b == ball)
				check[i]++;
		}
	}

	for (int i = 123; i <= 987; i++) {
		if (check[i] == N)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}