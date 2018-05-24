#include <iostream>
#include <cstdio>
#include <complex>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef complex<double> comp;

void fft(vector<comp> &a, int invert = 0) {
	int n = (int)a.size();
	int i, j, len;
	const double PI = 3.141592653589793238;
	for (i = 1, j = 0; i<n; i++) {
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1) j -= bit;
		j += bit;
		if (i < j) swap(a[i], a[j]);
	}
	for (len = 2; len <= n; len <<= 1) {
		double ang = 2 * PI / len * (invert ? -1 : 1);
		comp wlen = comp(cos(ang), sin(ang));
		for (i = 0; i<n; i += len) {
			comp w = 1;
			for (j = 0; j<len / 2; j++) {
				comp u = a[i + j], v = a[i + j + len / 2] * w;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert) for (i = 0; i<n; i++) a[i] /= n;
}
vector<int> multiply(vector<int> a, vector<int> b) {
	vector<int> res;
	vector<comp> fa(a.begin(), a.end()),
		fb(b.begin(), b.end());
	int i, n;
	for (n = 1; n < 2 * max(a.size(), b.size()); n *= 2);
	fa.resize(n), fb.resize(n);
	fft(fa), fft(fb);
	for (i = 0; i < n; i++) fa[i] *= fb[i];
	fft(fa, 1);
	res.resize(n);
	for (i = 0; i < n; i++)
		res[i] = (int)(fa[i].real() + 0.5);
	return res;
}

void mem(vector<int>&RPS, vector<int>&arr,int pos,int n,int m,string s,string t) {
	fill(RPS.begin(), RPS.end(), 0);
	fill(arr.begin(), arr.end(), 0);
	for (int i = 0; i < n; i++) {
		if (pos == 0 && s[i] == 'R') RPS[i] = 1;
		if (pos == 1 && s[i] == 'P') RPS[i] = 1;
		if (pos == 2 && s[i] == 'S') RPS[i] = 1;
	}
	for (int i = 0; i < m; i++) {
		if (pos == 0 && t[i] == 'P') arr[i] = 1;
		if (pos == 1 && t[i] == 'S') arr[i] = 1;
		if (pos == 2 && t[i] == 'R') arr[i] = 1;
	}
	reverse(arr.begin(), arr.end());
}
int main() {
	int n, m; scanf(" %d %d", &n, &m);
	string RPS, machine;
	cin >> RPS >> machine;
	vector<int> rps(n);
	vector<int> arr(m);
	vector<int> ans;
	int maxn = 0;
	for (int i = 0; i < 3; i++) {
		mem(rps, arr, i, n, m, RPS, machine);
		vector<int> FFT = multiply(rps, arr);
		int k = FFT.size();
		if (i == 0) ans.resize(k);
		for (int i = 0; i < k; i++) ans[i] += FFT[i];
	}
	for (int i = m - 1; i < ans.size(); i++) maxn = max(maxn, ans[i]);
	printf("%d\n", maxn);
}