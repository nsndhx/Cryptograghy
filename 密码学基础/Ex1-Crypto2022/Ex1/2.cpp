//#include<iostream>
//#include<math.h>
//#include<fstream>
//using namespace std;
/////根据书上所给的分析链，求出第五轮2、4位密钥
/////然后求出1、3位密钥
//
//int x[17], y[17], K[17], *L1, *L2, c[17][17], T=10000, m;//x为明文，y为密文, k为第五轮密钥, L1和L2为密钥，取值从1到16, c为计数数组，c[L1][L2]=count(L1,L2), T为明密文对数量
//int *v=new int [17], *u=new int [17];
//int X[10000][16],Y[10000][16];
//int pais[16];//s盒逆
//
//int sixteen(int n[4]){//2->10
//	int s=0;
//	for(int i=1;i<=4;i++)
//		s+=pow(2.0,4-i)*n[i-1];
//	return s;
//}
//
//int * two(int n){//10->2
//	int * s=new int [5];
//	s[1]=n/8;
//	n-=n/8*8;
//	s[2]=n/4;
//	n-=n/4*4;
//	s[3]=n/2;
//	n-=n/2*2;
//	s[4]=n;
//	return s;
//}
//void getxy(){
//	char *xx=new char [17];
//	char *yy=new char [17];
//	ifstream in;
//	in.open("D:/wtx/密码/密码学基础/Ex1-Crypto2022/Ex1/my3.txt");
//	int i=0,j=0;
//
//	for(j=0;j<T;j++){
//		for(i=1;i<17;i++){
//			in>>xx[i];
//			X[j][i]=xx[i]-48;
//		}
//		for(i=1;i<17;i++){
//			in>>yy[i];
//			Y[j][i]=yy[i]-48;
//		}
//	}
//}
//
//int *VtoU(int v[16]){
//	int *u=new int [20], n[4];
//	int i=0,j=0,k=5;
//	for(i=5;i<=8;i++){
//		n[j++]=v[i];
//		if(j==4){
//			int s=sixteen(n);
//			s=pais[s];
//			u[k++]=s/8;
//			s-=s/8*8;
//			u[k++]=s/4;
//			s-=s/4*4;
//			u[k++]=s/2;
//			s-=s/2*2;
//			u[k++]=s;
//		}
//	}
//	k=13,j=0;
//	for(i=13;i<=16;i++){
//		n[j++]=v[i];
//		if(j==4){
//			int s=sixteen(n);
//			s=pais[s];
//			u[k++]=s/8;
//			s-=s/8*8;
//			u[k++]=s/4;
//			s-=s/4*4;
//			u[k++]=s/2;
//			s-=s/2*2;
//			u[k++]=s;
//		}
//	}
//	return u;
//}
//
//void f24(){//利用线性分析求K<2>和K<4>
//	int i=0,j=0,k=0,l=0;
//	for(i=1;i<=16;i++){
//		for(j=1;j<=16;j++){
//			c[i][j]=0;
//		}
//	}
//	getxy();
//	//for each (x,y)
//	for(l=0;l<T;l++){
//		for(i=1;i<=16;i++){
//			x[i]=X[l][i];
//			y[i]=Y[l][i];
//		}
//
//		for(i=1;i<=16;i++){
//			L1=two(i-1);
//
//			for(j=1;j<=16;j++){
//				L2=two(j-1);
//
//				//int v<2> = L1 ^ y<2>
//				for(k=1;k<=4;k++){
//					v[4+k]=L1[k]^y[4+k];
//				}
//			
//				//int v<4> = L2 ^ y<4>
//				for(k=1;k<=4;k++){
//					v[12+k]=L2[k]^y[12+k];
//				}
//
//
//				u=VtoU(v);
//				//for(k=5;k<=8;k++){
//				//	cout<<u[k];
//				//}
//				//for(k=13;k<=16;k++){
//				//	cout<<u[k];
//				//}
//				//system("pause");
//
//
//				//z=x[5]^x[7]^x[8]^u6^u8^u14^u16//
//				int z=x[5]^x[7]^x[8]^u[6]^u[8]^u[14]^u[16];
//
//				//if z=0
//				//c[i][j]+=1
//				if(z==0){
//					c[i][j]+=1;
//				}
//			}
//		}
//	}
//	m=-1; //max赋初值
//	for(i=1;i<=16;i++){
//		L1=two(i-1);
//		for(j=1;j<=16;j++){
//			L2=two(j-1);
//			c[i][j]=abs(c[i][j]-T/2);//求绝对值
//			if(c[i][j] > m){
//				m=c[i][j];
//				//k=(L1,L2)
//				for(l=1;l<=4;l++){
//					K[4+l]=L1[l];
//					K[12+l]=L2[l];
//				}
//			}
//		}
//	}
//	//
//	for(i=5;i<=8;i++){
//		cout<<K[i];
//	}
//	for(i=13;i<=16;i++){
//		cout<<K[i];
//	}
//}
//
//void f13(){//求密钥K<1>和K<3>，暴力搜索
//}
//
//int main(){
//	pais[14]=0;pais[4]=1;pais[13]=2;pais[1]=3;pais[2]=4;pais[15]=5;pais[11]=6;pais[8]=7;
//	pais[3]=8;pais[10]=9;pais[6]=10;pais[12]=11;pais[5]=12;pais[9]=13;pais[0]=14;pais[7]=15;
//	f24();
//	system("pause");
//	return 0;
//}	
//
