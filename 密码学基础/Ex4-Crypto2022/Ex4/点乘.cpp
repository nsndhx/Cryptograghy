#include<iostream>
using namespace std;
long long int a, b, p;//y=x^3+a*x+b  mod p

struct point {
	long long int x;
	long long int y;
}p1, p2, pp;//p1Ϊ����ĵ㣬p2Ϊ��ӡ�ĵ㣬pp�����洢��;��ĵ�

long long int cifang(unsigned long long int a, long long int q)  //��a^q modp
{
	unsigned long long int y;

	//ʹ�ö�����ƽ���˷����� pow(a,q) % p
	y = 1;

	while (q != 0)
	{
		//����q�е�ÿ��1���ۼ�y

		if (q & 1)
			y = (y * a) % p;
		//����q�е�ÿһλ������a��ƽ��
		a = (a * a) % p;
		//׼��q�е���һλ
		q = q >> 1;
	}

	return (long long int)y;
}

point fx(point pp1, point pp2) {//x1!=x2
	point n;
	long long int kk = 0;

	//��pp1 pp2��һ��Ϊ(-1,-1)
	if (pp1.x == -1 && pp1.y == -1) {
		return pp2;
	}
	else if (pp2.x == -1 && pp2.y == -1) {
		return pp1;
	}

	//�����㶼��Ϊ(-1,-1)
	else {
		if (pp1.x == pp2.x) {//��������������

			if ((pp1.y + pp2.y) % p == 0) {//�������������Ϊ0����pp1+pp2=(-1,-1)
				n.x = -1;
				n.y = -1;
				return n;
			}

			else {//�������
				//kk=(3*x1^2+a)/(2*y1)  mod p
				long long int t = 3 * pp1.x;
				t %= p;
				t *= pp1.x;
				t %= p;
				t += a;
				t %= p;
				kk = t * cifang(2 * pp1.y, p - 2);
				kk %= p;
			}
		}

		else {//����������겻���
			//kk=(y2-y1)/(x2-x1)  mod p
			long long int t = pp2.y - pp1.y;
			while (t < 0) {
				t += p;
			}
			t %= p;
			long long int w = pp2.x - pp1.x;
			while (w < 0) {
				w += p;
			}
			w %= p;
			kk = t * cifang(w, p - 2);
			kk %= p;
		}
	}
	n.x = kk * kk - pp1.x - pp2.x;
	while (n.x < 0) {
		n.x += p;
	}
	n.x %= p;
	n.y = -pp1.y + kk * (pp1.x - n.x);
	while (n.y < 0) {
		n.y += p;
	}
	n.y %= p;
	return n;
}

void diancheng(long long int k) {
	if (k == 0) {
		cout << "-1 -1";
		return;
	}
	else {
		long long int i = 0;
		p2.x = -1;
		p2.y = -1;
		pp = p2;

		//��k��ֳ�2�Ĵη��ĺ�
		while (k != 0) {

			if (i == 0) {
				pp = p1;
			}
			else {
				pp = fx(pp, pp);
			}

			if (k & 1) {
				//��p2:  p2=p2+pp[i]
				p2 = fx(pp, p2);
			}
			k >>= 1;
			i++;
		}
		cout << p2.x << " " << p2.y;
		return;
	}
}
int main() {
	long long int k;
	cin >> a >> b >> p;
	cin >> p1.x >> p1.y >> k;
	diancheng(k);
	system("pause");
	return 0;
}