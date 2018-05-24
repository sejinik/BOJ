#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int tcase;
int sum;
int cnt;

double ave;
int mid;
int many;
int range;

set<pair<int,int>> s;
int arr[500010];

int main() {
	scanf("%d", &tcase);

	for (int i = 0; i < tcase; i++) {
		int num;
		scanf("%d", &num);
		arr[i] = num;
		s.insert({ 0,num });
		sum += num;
	}
	//Æò±Õ
	ave = (double)sum / (double)tcase;

	//Áß¾Ó°ª
	sort(arr, arr + tcase);
	mid = arr[tcase / 2];

	//ÃÖºó°ª
	vector<pair<int, int>> vt;
	int m_cnt = 0;
	for (int i = 0; i < tcase; i++) {
		int cnt = upper_bound(arr, arr + tcase, arr[i]) - lower_bound(arr, arr + tcase, arr[i]);
		
		m_cnt = max(cnt, m_cnt);
		if (i ==0 || (arr[i] != arr[i - 1])) 
			vt.push_back({ cnt,arr[i] });
	}

	int size = vt.size();
	vector<int> temp;
	for (int i = 0; i < size; i++) {
		if (m_cnt == vt[i].first)
			temp.push_back(vt[i].second);
	}

	if (temp.size() == 1)
		many = temp[0];
	else
		many = temp[1];
	
	//¹üÀ§
	range = arr[tcase - 1] - arr[0];

	printf("%.0lf\n", ave);
	printf("%d\n", mid);
	printf("%d\n", many);
	printf("%d\n", range);
	return 0;
}