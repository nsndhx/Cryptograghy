#include"hhh.h"
//f():��ָ��
//pow():����
int main() {
	/*
	* input
	* p:������p=2q+1
	* g:����Ԫ
	* q:������
	* a:˽Կ
	* k:�����
	* r:�����Ӧ
	*/
	int g, q, a, k, r;
	cin >> g >> q >> a >> k >> r;
	//int g = 4, q = 5, a = 3, k = 3, r = 2;
	int v, p, gama, y;
	p = 2 * q + 1;
	v = pow(g, q - a, p);
	//Alice�������һ��k
	//gama=g^k mod p
	gama = pow(g, k, p);
	//Bobѡ��һ�������Ӧr
	//Alice������Ӧy
	y = k + a * r;
	y %= q;
	//Bob��֤gama
	/*
	* output
	* v:��Կ  g^(q-a) mod p
	* ��:������֤����Ϣ  g^k mod p
	* y:Alice����Ӧ  k+ar mod q    ��=g^y*v^r mod p
	*/
	cout << v << endl << gama << endl << y << endl;
	system("pause");
	return 0;
}