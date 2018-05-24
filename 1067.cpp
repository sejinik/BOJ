#include <iostream>
#include <cstdio>
#include <complex>
#include <algorithm>
#include <vector>
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

int main() {
	int n; scanf(" %d", &n);
	vector<int> a(n * 2);
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		int x; scanf(" %d", &x);
		a[i] = a[i + n] = x;
	}
	for (int i = 0; i < n; i++) scanf(" %d", &b[i]);
	reverse(b.begin(), b.end());
	vector<int> FFT = multiply(a, b);
	int ans = 0;
	for (int i = n; i < n * 2; i++) ans = max(ans, FFT[i]);
	printf("%d\n", ans);
}