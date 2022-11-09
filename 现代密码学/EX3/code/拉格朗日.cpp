#include"hhh.h"
#pragma warning(disable : 4700)
#pragma warning(disable : C6001)

int modx(int x, int y, int mod) {
	while (x < 0 || y < 0) {
		x += mod;
		y += mod;
	}
	x %= mod;
	y %= mod;
	int sum = 0;
	while (x != 0) {
		if (x & 1) {
			sum += y;
			sum %= mod;
		}
		y = y << 1;
		x = x >> 1;
	}
	return sum;
}
int modj(int x, int y, int mod) {
	int z = x - y;
	while (z < 0) {
		z += mod;
	}
	return z % mod;
}

int main() {
	//input:
	//p:素数模数
	//m:多项式次数
	//y[i]:Z_p中的m+1个元素y_i
	//a[i]:y[i]对应的多项式a_i(x)
	
	int p = 0, m = 0, * y, ** a;
	int i = 0, j = 0, h = 0;
	cin >> p >> m;
	y = new int[m + 3];
	a = new int* [m + 3];
	for (i = 1; i <= m + 1; i++) {
		a[i] = new int [m + 2];//a[i][j]代表y[i]对应的多项式为a[i][]
							 //该多项式x^j的系数为a[i][j]
	}
	for (i = 1; i <= m + 1; i++) {
		cin >> y[i];
	}
	for (i = 1; i <= m + 1; i++) {
		for (j = 0; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	/*int p = 13, m = 2, y[4], a[4][3];
	int i = 0, j = 0, h = 0;
	y[1] = 1, y[2] = 2, y[3] = 3;
	a[1][0] = 1, a[1][1] = 1, a[1][2] = 1;
	a[2][0] = 7, a[2][1] = 0, a[2][2] = 4;
	a[3][0] = 2, a[3][1] = 9, a[3][2] = 0;
	*/
	int** z;//存储Π(y-yh)/(yj-yh)的值
	z = new int*[m + 3];
	for (i = 1; i <= m + 1; i++) {
		z[i] = new int[m + 2];
	}
	for (i = 1; i <= m + 1; i++) {
		z[i][0] = 1;
		for (j = 1; j <= m; j++) {
			z[i][j] = 0;
		}
	}
	//int test1[3] = { 1,1,0 }, test2[2] = { 1,1 };
	//int *test = { 0 };
	//test=yx(test1, test2, p, 1);
	//for (i = 2; i >= 0; i--) {
	//	cout << test[i] << " ";
	//}
	for (j = 1; j <= m + 1; j++) {
		int c = 0;//记录z[j][]的最高次数
		for (h = 1; h <= m + 1; h++) {
			//k=1/(y[j]-y[h]) mod p
			int k = modj(y[j], y[h], p);
			k = pow(k, p - 2, p);//k=1/k mod p
			//cout << "k:" << k << endl;
			int t = modx(-y[h], k, p);
			//cout << "t:" << t << endl;
			//计算z[j]
			if (h != j) {
				for (i = c; i >= 0; i--) {
					z[j][i + 1] = modx(z[j][i], k, p) + modx(z[j][i + 1], t, p);
					z[j][i + 1] %= p;
				}
				z[j][0] = modx(z[j][0], t, p);
				c++;
				//cout << "a" << j << "第" << c+1 << "轮z：" << endl;
				/*for (int ff = c; ff >= 0; ff--) {
					cout << z[j][ff] << " ";
					if (ff == 0) {
						cout << endl;
					}
				}*/
			}
		}
		
	}
	//output:
	//A(x,y)的所有系数(m+1)方阵
	int** A;//存储Π(y-yh)/(yj-yh)的值
	A = new int* [m + 2];
	for (i = 0; i <= m; i++) {
		A[i] = new int [m + 2];
	}
	for (i = 0; i <= m; i++) {
		for (j = 0; j <= m; j++) {
			A[i][j] = 0;
		}
	}
	for (j = 1; j <= m + 1; j++) {
		for (i = 0; i <= m; i++) {//x^i
			for (h = 0; h <= m; h++) {//y^h
				A[i][h] += modx(a[j][i], z[j][h], p);
				A[i][h] %= p;
			}
		}
		/*
		cout << "a" << j << "*z" << j << ":" << endl;
		for (i = 0; i <= m; i++) {
			for (h = 0; h <= m; h++) {
				cout << A[i][h] << " ";
			}
			cout << endl;
		}
		*/
	}
	for (i = 0; i <= m; i++) {
		for (j = 0; j <= m; j++) {
			cout << A[i][j] << " ";
			if (j == m) {
				cout << endl;
			}
		}
	}
	system("pause");
	return 0;
}