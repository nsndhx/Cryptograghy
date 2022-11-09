#include"hhh.h"
int main() {
	/*
	* input
	* p:素数，p=2q+1
	* g:生成元
	* q:素数阶
	* v:公钥  g^(q-a) mod p
	* r1:随机挑战
	* r2:随机挑战
	* y1:随机响应
	* y2:随机响应
	*/
	int g, q, v, r1, y1, r2, y2;
	cin >> g >> q >> v >> r1 >> y1 >> r2 >> y2;
	//int g = 4, q = 5, v = 5, r1 = 2, y1 = 4, r2 = 1, y2 = 1;
	int p, gama, k1;
	int a;
	p = 2 * q + 1;
	//g^k1=g^y1*v^r1 mod p
	k1 = f(g, (pow(g, y1, p) * pow(v, r1, p)) % p, p);
	while ((y1 - k1) % r1 != 0) {
		y1 +=  q;
	}
	a = (y1 - k1) / r1;
	/*
	* output
	* a:私钥
	*/
	cout << a << endl;
	system("pause");
	return 0;
}