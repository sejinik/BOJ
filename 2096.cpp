#include <iostream>
#include <algorithm>
using namespace std;

int Bdp[2][3]; //최대값저장
int Sdp[2][3]; //최소값저장
int arr[100010][3]; //저장된값

int main() {
	int num;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		for (int j = 0; j < 3; j++)
			scanf("%d", &arr[i][j]);
	}

	Bdp[1][0] = Sdp[1][0] = arr[1][0];
	Bdp[1][1] = Sdp[1][1] = arr[1][1];
	Bdp[1][2] = Sdp[1][2] = arr[1][2];

	for (int i = 2; i <= num; i++) {
			Bdp[i%2][0] = max(Bdp[(i - 1)%2][0], Bdp[(i - 1)%2][1]) + arr[i][0];
			Bdp[i%2][1] = max(max(Bdp[(i - 1) % 2][0], Bdp[(i - 1) % 2][1]), Bdp[(i - 1) % 2][2]) + arr[i][1];
			Bdp[i%2][2] = max(Bdp[(i - 1) % 2][1], Bdp[(i - 1) % 2][2]) + arr[i][2];

			Sdp[i%2][0] = min(Sdp[(i - 1) % 2][0], Sdp[(i - 1) % 2][1]) + arr[i][0];
			Sdp[i%2][1] = min(min(Sdp[(i - 1) % 2][0], Sdp[(i - 1) % 2][1]), Sdp[(i - 1) % 2][2]) + arr[i][1];
			Sdp[i%2][2] = min(Sdp[(i - 1) % 2][1], Sdp[(i - 1) % 2][2]) + arr[i][2];
	}
	if(num%2 !=0)
		printf("%d %d\n", max(max(Bdp[1][0], Bdp[1][1]), Bdp[1][2]), min(min(Sdp[1][0], Sdp[1][1]), Sdp[1][2]));
	else
		printf("%d %d\n", max(max(Bdp[0][0], Bdp[0][1]), Bdp[0][2]), min(min(Sdp[0][0], Sdp[0][1]), Sdp[0][2]));
	return 0;
}