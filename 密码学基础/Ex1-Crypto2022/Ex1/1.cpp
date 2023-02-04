//#include<iostream>
//#include<math.h>
//#include<fstream>
//using namespace std;
//
//int T=10000;
//int *x=new int [17], k[16], *y=new int [17],X[10000][16];//x为明文，K为密钥，k为轮密钥，y为密文
//int l=4,m=4,Nr=4;
//int pais[16], paip[17];
//int	K[32]={0,1,0,0,1,0,1,1,1,0,0,1,1,1,1,0,0,1,0,0,0,1,0,1,1,0,1,1,0,1,1,0};
//
//
//int sixteen(int n[4]){
//	int s=0;
//	for(int i=1;i<=4;i++)
//		s+=pow(2.0,4-i)*n[i-1];
//	return s;
//}
//
////计算v
//int *UtoV(int u[16]){
//	int *v=new int [20], n[4];
//	int i=0,j=0,k=0;
//	for(i=0;i<16;i++){
//		n[j++]=u[i];
//		if(j==4){//4位一组，转成16进制，进行pais置换，并转换成二进制放在数组v中
//			int s=sixteen(n);
//			s=pais[s];
//			v[k++]=s/8;
//			s-=s/8*8;
//			v[k++]=s/4;
//			s-=s/4*4;
//			v[k++]=s/2;
//			s-=s/2*2;
//			v[k++]=s;
//			j=0;
//		}
//	}
//	return v;
//}
//
//void get(){
//	int i=0,j=0;
//	ifstream in;
//	in.open("D:/wtx/密码/密码学基础/Ex1-Crypto2022/Ex1/M.txt");
//	char xx[16];
//	for(j=0;j<T;j++){
//		for(i=0;i<16;i++){
//			in>>xx[i];
//			X[j][i]=xx[i]-48;
//		}
//	}
//}
//
//void SPN(){
//	int *w=new int [16], *u=new int [16],*v=new int [20];
//	int i=0,j=0;
//	
//	//w0=x
//	//cout<<"w0: ";
//	for(i=0;i<16;i++){
//		w[i]=x[i];
//		//cout<<w[i]<<" ";
//		//cout<<w[i];
//	}
//	//cout<<endl;
//	
//	for(i=1;i<=Nr-1;i++){
//		
//		//k[0]=K[4i-3];
//		//cout<<"k"<<i<<": ";
//		for(j=0;j<16;j++){
//			k[j]=K[(4*i-4)+j];
//			//cout<<k[j]<<" ";
//		}
//		//cout<<endl;
//		
//		//u=w异或k
//		//cout<<"u"<<i<<": ";
//		for(j=0;j<16;j++){
//			u[j]=w[j]^k[j];
//			//cout<<u[j]<<" ";
//		}
//		//cout<<endl;
//		
//		//计算v
//		//cout<<"v"<<i<<": ";
//		v=UtoV(u);
//		//for(j=0;j<16;j++)
//			//cout<<v[j]<<" ";
//		//cout<<endl;
//
//		//w=v paip//在v中的z位对应w中的paip(z)位
//		//cout<<"w"<<i<<": ";
//		for(j=0;j<16;j++)
//			w[paip[j+1]-1]=v[j];
//		//for(j=0;j<16;j++)
//			//cout<<w[j]<<" ";
//		//cout<<endl;
//	}
//	//kNr
//	//cout<<"k"<<Nr<<": ";
//	for(j=0;j<16;j++){
//		k[j]=K[12+j];
//		//cout<<k[j]<<" ";
//	}
//	//cout<<endl;
//
//	//u=w异或k
//	//cout<<"u"<<Nr<<": ";
//	for(j=0;j<16;j++){
//		u[j]=w[j]^k[j];
//		//cout<<u[j]<<" ";
//	}
//	//cout<<endl;
//
//	//v'
//	//cout<<"v"<<Nr<<": ";
//	v=UtoV(u);
//	//for(j=0;j<16;j++)
//		//cout<<v[j]<<" ";
//	//cout<<endl;
//
//	//k
//	//cout<<"k"<<Nr+1<<": ";
//	for(j=0;j<16;j++){
//		k[j]=K[16+j];
//		//cout<<k[j]<<" ";
//	}
//	//cout<<endl;
//
//	//y=v异或k
//	//cout<<"y:  ";
//	for(j=0;j<16;j++){
//		y[j]=v[j]^k[j];
//		//cout<<y[j]<<" ";
//		//cout<<y[j];
//	}
//	//cout<<endl;
//}
//
//int main(){
//	pais[0]=14;pais[1]=4;pais[2]=13;pais[3]=1;pais[4]=2;pais[5]=15;pais[6]=11;pais[7]=8;
//	pais[8]=3;pais[9]=10;pais[10]=6;pais[11]=12;pais[12]=5;pais[13]=9;pais[14]=0;pais[15]=7;
//	paip[1]=1;paip[2]=5;paip[3]=9;paip[4]=13;paip[5]=2;paip[6]=6;paip[7]=10;paip[8]=14;
//	paip[9]=3;paip[10]=7;paip[11]=11;paip[12]=15;paip[13]=4;paip[14]=8;paip[15]=12;paip[16]=16;
//	int i=0,j=0;
//	get();
//	ofstream outfile;
//	outfile.open("D:/wtx/密码/密码学基础/Ex1-Crypto2022/Ex1/my3.txt");
//	for(i=0;i<T;i++){
//		for(j=0;j<16;j++){
//			x[j]=X[i][j];
//			outfile<<x[j];
//		}
//		outfile<<endl;
//		SPN();
//		for(j=0;j<16;j++){
//			outfile<<y[j];
//			//cout<<y[j];
//		}
//		outfile<<endl;
//		//cout<<endl;
//		//system("pause");
//	}
//
//	system("pause");
//	return 0;
//}