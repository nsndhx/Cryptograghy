#include"hhh.h"
//f():求指数
//pow():求幂
int main() {
	/*
	* input
	* p:素数，p=2q+1
	* g:生成元
	* q:素数阶
	* a:私钥
	* k:随机数
	* r:随机响应
	*/
	int g, q, a, k, r;
	cin >> g >> q >> a >> k >> r;
	//int g = 4, q = 5, a = 3, k = 3, r = 2;
	int v, p, gama, y;
	p = 2 * q + 1;
	v = pow(g, q - a, p);
	//Alice随机生成一个k
	//gama=g^k mod p
	gama = pow(g, k, p);
	//Bob选择一个随机响应r
	//Alice计算响应y
	y = k + a * r;
	y %= q;
	//Bob验证gama
	/*
	* output
	* v:公钥  g^(q-a) mod p
	* γ:用于验证的信息  g^k mod p
	* y:Alice的响应  k+ar mod q    γ=g^y*v^r mod p
	*/
	cout << v << endl << gama << endl << y << endl;
	system("pause");
	return 0;
}