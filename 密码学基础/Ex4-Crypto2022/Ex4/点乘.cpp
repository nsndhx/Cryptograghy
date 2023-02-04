#include<iostream>
using namespace std;
long long int a, b, p;//y=x^3+a*x+b  mod p

struct point {
	long long int x;
	long long int y;
}p1, p2, pp;//p1为输入的点，p2为打印的点，pp用来存储中途求的点

long long int cifang(unsigned long long int a, long long int q)  //求a^q modp
{
	unsigned long long int y;

	//使用二进制平方乘法计算 pow(a,q) % p
	y = 1;

	while (q != 0)
	{
		//对于q中的每个1，累加y

		if (q & 1)
			y = (y * a) % p;
		//对于q中的每一位，计算a的平方
		a = (a * a) % p;
		//准备q中的下一位
		q = q >> 1;
	}

	return (long long int)y;
}

point fx(point pp1, point pp2) {//x1!=x2
	point n;
	long long int kk = 0;

	//当pp1 pp2有一个为(-1,-1)
	if (pp1.x == -1 && pp1.y == -1) {
		return pp2;
	}
	else if (pp2.x == -1 && pp2.y == -1) {
		return pp1;
	}

	//两个点都不为(-1,-1)
	else {
		if (pp1.x == pp2.x) {//两个点横坐标相等

			if ((pp1.y + pp2.y) % p == 0) {//两个点纵坐标和为0，即pp1+pp2=(-1,-1)
				n.x = -1;
				n.y = -1;
				return n;
			}

			else {//其他情况
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

		else {//两个点横坐标不相等
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

		//将k拆分成2的次方的和
		while (k != 0) {

			if (i == 0) {
				pp = p1;
			}
			else {
				pp = fx(pp, pp);
			}

			if (k & 1) {
				//求p2:  p2=p2+pp[i]
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