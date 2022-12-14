#include<iostream>
using namespace std;

int t, w, p;//公共参数
int** A = new int*;//增广矩阵
int* a = new int;//存储a_i

int pow(int x, int i, int mod) {//x^i mod 
	int s = 1;
	while (i != 0) {
		s *= x;
		s %= mod;
		i--;
	}
	return s;
}

int modj(int x, int y) {//x-y
	int z = x - y;
	while (z < 0) {
		z += p;
	}
	return z % p;
}
int modx(int x, int y) {//x*y
	while (x < 0 || y < 0) {
		x += p;
		y += p;
	}
	x %= p;
	y %= p;
	int sum = 0;
	while (x != 0) {
		if (x & 1) {
			sum += y;
			sum %= p;
		}
		y = y << 1;
		x = x >> 1;
	}
	return sum;
}
int modc(int x, int y) {//x/y=x*y^(-1)
	y = pow(y, p - 2, p);
	int z = modx(x, y);
	return z;
}

int a_x(int* a, int x) {//根据a和x求y的值
	int sum = a[1];
	for (int i = 2; i <= t; i++) {
		sum += a[i] * pow(x, i - 1, p);
		sum %= p;
	}
	return sum;
}

bool solve() {//求解a
	for (int i = 1; i <= t; i++)
	{
		//寻找第 i 列不为零的元素
		int k;
		for (k = i; k <= t; k++)
		{
			if (fabs(A[k][i]) > 1e-10) //满足这个条件时，认为这个元素不为0
				break;
		}
		if (k <= t)//说明第 i 列有不为0的元素
		{
			//交换第 i 行和第 k 行所有元素
			for (int j = i; j <= t+1; j++)//从第 i 个元素交换即可，因为前面的元素都为0
			{
				int temp = A[i][j];
				A[i][j] = A[k][j];
				A[k][j] = temp;
			}
			double c;//倍数
			for (int j = i + 1; j <= t; j++)
			{
				c = modc(p - A[j][i], A[i][i]);
				for (k = i; k <= t+1; k++)
				{
					A[j][k] += modx(c, A[i][k]);//第 i 行 a 倍加到第 j 行
					A[j][k] %= p;
				}
			}
		}
		else //没有找到则说明系数矩阵秩不为 n ，说明方程组中有效方程的个数小于 n
		{
			cout << "系数矩阵奇异，线性方程组无解或有无数解" << endl;
			return false;
		}
	}
	//自下而上求解
	for (int i = t; i >= 1; i--)
	{
		a[i] = A[i][t + 1];
		for (int j = t; j > i; j--)
		{
			a[i] = modj(a[i], modx(a[j], A[i][j]));
		}
		a[i] = modc(a[i], A[i][i]);
	}
	return true;
}

/*
Input:
t、w、p:公共参数
x_i,y_i:(x,y)
x'

Output:
k:a0
y'
*/

int main() {
	cin >> t >> w >> p;
	//t = 3; w = 5; p = 19;
	a = new int[t + 2];
	int* x = new int[t + 3];
	int* y = new int[t + 3];
	int i = 0;
	for (i = 1; i <= t; i++) {
		cin >> x[i] >> y[i];
	}
	//x[1] = 1; x[2] = 3; x[3] = 5;
	//y[1] = 1; y[2] = 4; y[3] = 6;
	cin >> x[t + 1];
	//x[4] = 10;

	//求出*a
	A = new int* [t + 2];
	for (i = 1; i <= t; i++) {
		A[i] = new int[t + 3];
		for (int j = 1; j <= t; j++) {
 			A[i][j] = pow(x[i], j - 1, p);
		}
		A[i][t + 1] = y[i];
	}
	/*cout << "增广矩阵为:" << endl;
	for (i = 1; i <= t; i++) {
		for (int j = 1; j <= t + 1; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}*/

	if (solve() != true) {
		return -1;
	}

	/*cout << "a:" << endl;
	for (i = 1; i <= t; i++) {
		cout << a[i] << " ";
	}
	cout << endl;*/

	cout << "k：" << a[1] << endl;
	y[t + 1] = a_x(a, x[t + 1]);
	cout << "y'：" << y[t + 1] << endl;
	system("pause");
	return 0;
}