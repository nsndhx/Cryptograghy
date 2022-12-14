#include<iostream>
using namespace std;

/*
Input:
t、w、p:公共参数
k(a0):密钥
a1……a_(t-1):
x1……x_w:公开坐标

Output:
y1……y_w:x对应的y
*/

int pow(int x, int i, int mod) {//x^i mod 
	int s = 1;
	while (i != 0) {
		s *= x;
		s %= mod;
		i--;
	}
	return s;
}
int a_x(int* a, int mod, int x, int t) {
	int sum = a[0];
	for (int i = 1; i < t; i++) {
		sum += a[i] * pow(x, i, mod);
		sum %= mod;
	}
	return sum;
}
int main() {
	int t, w, p;
	cin >> t >> w >> p;
	int* a = new int[t + 1];
	int* x = new int[w + 2];
	int* y = new int[w + 2];
	int i = 0;
	for (i = 0; i < t; i++) {
		cin >> a[i];
	}
	for (i = 1; i <= w; i++) {
		cin >> x[i];
		y[i] = 0;
	}
	for (i = 1; i <= w; i++) {
		y[i] = a_x(a, p, x[i], t);
		cout << y[i] << " ";
	}
	system("pause");
	return 0;
}