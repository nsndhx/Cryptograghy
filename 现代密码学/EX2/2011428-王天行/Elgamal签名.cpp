#include<iostream>
using namespace std;
int f(int x,int y,int mod) {//y=x^a mod
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
int pow(int x, int e, int n) {//计算x^e mod n
	int m = 1;
	while (e > 0) {
		if (e & 1)
			m = (m * x) % n;
		x = (x * x) % n;
		e = e >> 1;
	}
	return m;
}
bool vrfy(int g, int q, int p, int m, int x, int y) {
	int z1 = 0, z2 = 0, z = 0;
	z1 = pow(q, x, p);
	z2 = pow(x, y, p);
	z = pow(g, m, p);
	if (z1 * z2 % p == z) {
		return true;
	}
	else return false;
}
int main() {
	//in：
	//公钥(p,g,q),消息m,签名(x,y),私钥a,随机值r
	//g^a=q mod p   sig(m,k)=(x,y)   x=g^r mod p,y=(m-ax)k^(-1) mod p-1
	//ver(m,(x,y))==true <=> q^x*x^y=g^m mod p
	int p, g, q, m, x, y, a = 0, r = 0;
	cin >> p >> g >> q >> m >> x >> y;
	//p = 11; g = 2; q = 9; m = 8; x = 7; y = 8;
	a = f(g, q, p);
	r = f(g, x, p);
	//out：
	if (vrfy(g, q, p, m, x, y)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	cout << a << endl << r << endl;
	system("pause");
	return 0;
}