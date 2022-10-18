#include <iostream>
using namespace std;

long long int pow(long long int x, long long int e, long long int n) {//计算x^e mod n
    long long int m = 1;
    while (e > 0) {
		if (e & 1)
			m = (m * x) % n;
		x = (x * x) % n;
		e = e >> 1;
	}
	return m;
}
int main() {
	long long int n = 0, p = 0, q = 0, e = 0, t = 0, i = 0;
	int z[1000];
	long long int s[1000];
	//input
	cin >> n >> p >> q >> e >> s[0] >> i;
	//code
	long long int j = 0;
	for (j = 0; ; j++) {
		//s[j+1]=s[j]^e mod n
		s[j + 1] = pow(s[j], e, n);
		//z[j+1]=s[j+1] mod 2
		if (j < i) 
			z[j] = s[j + 1] % 2;
		//计算周期(穷举）
		if (t == 0) {
			for (int k = 0; k <= j; k++) {
				if (s[k] == s[j + 1])
					t = j + 1 - k;
				break;
			}
		}
		if (t != 0 && j >= i)break;
	}
	//output
	cout << t << endl;
	for (j = 0; j < i; j++) {
		cout << z[j];
	}
	system("pause");
	return 0;
}