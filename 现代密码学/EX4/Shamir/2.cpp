#include<iostream>
using namespace std;

int t, w, p;//��������
int** A = new int*;//�������
int* a = new int;//�洢a_i

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

int a_x(int* a, int x) {//����a��x��y��ֵ
	int sum = a[1];
	for (int i = 2; i <= t; i++) {
		sum += a[i] * pow(x, i - 1, p);
		sum %= p;
	}
	return sum;
}

bool solve() {//���a
	for (int i = 1; i <= t; i++)
	{
		//Ѱ�ҵ� i �в�Ϊ���Ԫ��
		int k;
		for (k = i; k <= t; k++)
		{
			if (fabs(A[k][i]) > 1e-10) //�����������ʱ����Ϊ���Ԫ�ز�Ϊ0
				break;
		}
		if (k <= t)//˵���� i ���в�Ϊ0��Ԫ��
		{
			//������ i �к͵� k ������Ԫ��
			for (int j = i; j <= t+1; j++)//�ӵ� i ��Ԫ�ؽ������ɣ���Ϊǰ���Ԫ�ض�Ϊ0
			{
				int temp = A[i][j];
				A[i][j] = A[k][j];
				A[k][j] = temp;
			}
			double c;//����
			for (int j = i + 1; j <= t; j++)
			{
				c = modc(p - A[j][i], A[i][i]);
				for (k = i; k <= t+1; k++)
				{
					A[j][k] += modx(c, A[i][k]);//�� i �� a ���ӵ��� j ��
					A[j][k] %= p;
				}
			}
		}
		else //û���ҵ���˵��ϵ�������Ȳ�Ϊ n ��˵������������Ч���̵ĸ���С�� n
		{
			cout << "ϵ���������죬���Է������޽����������" << endl;
			return false;
		}
	}
	//���¶������
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
t��w��p:��������
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

	//���*a
	A = new int* [t + 2];
	for (i = 1; i <= t; i++) {
		A[i] = new int[t + 3];
		for (int j = 1; j <= t; j++) {
 			A[i][j] = pow(x[i], j - 1, p);
		}
		A[i][t + 1] = y[i];
	}
	/*cout << "�������Ϊ:" << endl;
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

	cout << "k��" << a[1] << endl;
	y[t + 1] = a_x(a, x[t + 1]);
	cout << "y'��" << y[t + 1] << endl;
	system("pause");
	return 0;
}