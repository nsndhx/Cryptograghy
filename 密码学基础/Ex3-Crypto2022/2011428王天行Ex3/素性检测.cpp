#include<iostream>
using namespace std;

long long int n, q = 0, k = 0;

long long int cifang(long long int a, long long int q)  //求a^q modn
{
	long long int y;

	//使用二进制平方乘法计算 pow(a,b) % n
	y = 1;

	while (q != 0)
	{
		//对于b中的每个1，累加y

		if (q & 1)
			y = (y * a) % n;
		//对于b中的每一位，计算a的平方
		a = (a * a) % n;
		//准备b中的下一位
		q = q >> 1;
	}

	return y;
}

void getqk() {
	q = 0;
	long long int s = n - 1;
	for (; s % 2 == 0;) {
		s /= 2;
		q += 1;
	}
	k = s;
}

void suxingjiance() {
	getqk();
	int t = 0;
	long long int a = 0;

	//随机选取2~n-2的一个数
	a = (rand() % (n - 1)) + 1;
	long long int b = cifang(a, k);
	if (b == 1) {
		cout << "Yes";
		return;
	}
	else {
		long long int j = 0;
		for (j = 0; j < q; j++) {
			if (b == n - 1) {
				cout << "Yes";
				return;
			}
			else {
				b = cifang(b, 2);
			}
		}
	}
	cout << "No";
}

int main() {
	cin >> n;
	if (n > 2 && n % 2 == 0) {
		cout << "No";
	}
	else {
		suxingjiance();
	}
	system("pause");
	return 0;
}