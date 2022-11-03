#include<iostream>
using namespace std;
int f(int x, int y, int mod) {//y=x^a mod
	int a = 0, m = 1;
	if (y == 1) {
		return 0;
	}
	++a;
	while (m * x % mod != y) {
		++a;
		m *= x;
		m %= mod;
	}
	return a;
}
int pow(int x, int e, int n) {//¼ÆËãx^e mod n
	int m = 1;
	while (e > 0) {
		if (e & 1)
			m = (m * x) % n;
		x = (x * x) % n;
		e = e >> 1;
	}
	return m;
}
