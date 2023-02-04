//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <iostream>
//#include <iomanip>
//using namespace std;
//
////密钥对应的扩展数组
//static int w[44];
//
///////
// // S盒
// ///
//static const int S[16][16] = { 0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
//	0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
//	0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
//	0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
//	0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
//	0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
//	0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
//	0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
//	0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
//	0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
//	0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
//	0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
//	0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
//	0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
//	0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
//	0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16 };
//
//
///////
// // 获取整形数据的低8位的左4个位
// ///
//static int getLeft4Bit(int num) {
//	int left = num & 0x000000f0;
//	return left >> 4;
//}
//
///////
// // 获取整形数据的低8位的右4个位
// ///
//static int getRight4Bit(int num) {
//	return num & 0x0000000f;
//}
//
///////
// //把字符转换为16进制整型
// ///
//static int get(char s) {
//	if (s >= '0' && s <= '9') {
//		return s - '0';
//	}
//	else {
//		switch (s) {
//		case 'a':
//			return 10;
//		case 'b':
//			return 11;
//		case 'c':
//			return 12;
//		case 'd':
//			return 13;
//		case 'e':
//			return 14;
//		case 'f':
//			return 15;
//		}
//	}
//}
//
///////
// // 把16个字符转变成4X4的数组，
// // 该矩阵中字节的排列顺序为从上到下，
// // 从左到右依次排列。
// ///
//static void convertToIntArray(char* s, int pa[4][4]) {
//	int k = 0;
//	int i, j;
//	for (i = 0; i < 4; i++)
//		for (j = 0; j < 4; j++) {
//			pa[j][i] = (get(s[k]) << 4) | get(s[k + 1]);
//			k += 2;
//		}
//}
//
///////
// // 打印4X4的数组
// ///
//static void printArray(int a[4][4]) {
//	int i, j;
//	for (i = 0; i < 4; i++) {
//		for (j = 0; j < 4; j++)
//			cout << setw(2) << setfill('0') << hex << uppercase << a[j][i];
//	}
//	//printf("\n");
//}
//
//
///////
// // 把连续的4个字符合并成一个4字节的整型
// ///
//static int getWordFromStr(char* s) {
//	int one, two, three, four, five, six, seven, eight;
//	one = get(s[0]);
//	one = one << 28;
//	two = get(s[1]);
//	two = two << 24;
//	three = get(s[2]);
//	three = three << 20;
//	four = get(s[3]);
//	four = four << 16;
//	five = get(s[4]);
//	five = five << 12;
//	six = get(s[5]);
//	six = six << 8;
//	seven = get(s[6]);
//	seven = seven << 4;
//	eight = get(s[7]);
//	return one | two | three | four | five | six | seven | eight;
//}
//
///////
// // 把一个4字节的数的第一、二、三、四个字节取出，
// // 入进一个4个元素的整型数组里面。
// ///
//static void splitIntToArray(int num, int array[4]) {
//	int one, two, three;
//	one = num >> 24;
//	array[0] = one & 0x000000ff;
//	two = num >> 16;
//	array[1] = two & 0x000000ff;
//	three = num >> 8;
//	array[2] = three & 0x000000ff;
//	array[3] = num & 0x000000ff;
//}
//
///////
// // 将数组中的元素循环左移step位
// ///
//static void leftLoop4int(int array[4], int step) {
//	int temp[4];
//	int i;
//	int index;
//	for (i = 0; i < 4; i++)
//		temp[i] = array[i];
//	index = step % 4 == 0 ? 0 : step % 4;
//	for (i = 0; i < 4; i++) {
//		array[i] = temp[index];
//		index++;
//		index = index % 4;
//	}
//}
//
///////
// // 把数组中的第一、二、三和四元素分别作为
// // 4字节整型的第一、二、三和四字节，合并成一个4字节整型
// ///
//static int mergeArrayToInt(int array[4]) {
//	int one = array[0] << 24;
//	int two = array[1] << 16;
//	int three = array[2] << 8;
//	int four = array[3];
//	return one | two | three | four;
//}
//
///////
// // 字节代换
// ///
// //用s盒对state进行代换
//int gets(int n) {
//	int S_Table[16][16] =
//	{ 0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
//	 0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
//	 0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
//	 0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
//	 0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
//	 0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
//	 0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
//	 0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
//	 0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
//	 0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
//	 0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
//	 0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
//	 0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
//	 0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
//	 0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
//	 0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16 };
//	int x = getLeft4Bit(n);
//	int y = getRight4Bit(n);
//	int result = S_Table[x][y];
//	return result;
//}
//void SubBytes(int array[4][4]) {
//	int i = 0, j = 0;
//	for (i = 0; i < 4; i++) {
//		for (j = 0; j < 4; j++) {
//			array[i][j] = gets(array[i][j]);
//		}
//	}
//}
//
//
////密钥扩展为w[44]
//void KeyExpansion(char* key) {
//	//RCon
//	unsigned int Rcon[10] = { 0x01000000, 0x02000000,
//					0x04000000, 0x08000000,
//					0x10000000, 0x20000000,
//					0x40000000, 0x80000000,
//					0x1b000000, 0x36000000 };
//	int i = 0, j = 0;
//	int numArray[4];
//	//w[i]<-(key[4i],key[4i+1],key[4i+2],key[4i+3])
//	for (i = 0; i < 4; i++) {
//		w[i] = getWordFromStr(key + i * 8);//把连续的4个字符合并成一个4字节的整型
//	}
//	for (i = 4; i < 44; i++) {
//		//temp<-w[i-1]
//		int temp = w[i - 1];
//		splitIntToArray(temp, numArray);//把一个4字节的数的第一、二、三、四个字节取出，入进一个4个元素的整型数组里面。
//		if (i % 4 == 0) {
//			//temp<-SubWord(RotWord(temp))^RCon[i/4]
//			leftLoop4int(numArray, 1);//numArray左移1位
//			for (j = 0; j < 4; j++) {
//				numArray[j] = gets(numArray[j]);
//			}
//			temp = mergeArrayToInt(numArray);//将数组变为整型
//			temp = temp ^ Rcon[i / 4 - 1];
//		}
//		w[i] = w[i - 4] ^ temp;
//	}
//}
//
///////
// // 轮密钥加
// ///
//static void addRoundKey(int array[4][4], int round) {
//	int warray[4];
//	int i, j;
//	for (i = 0; i < 4; i++) {
//
//		splitIntToArray(w[round * 4 + i], warray);
//
//		for (j = 0; j < 4; j++) {
//			array[j][i] = array[j][i] ^ warray[j];
//		}
//	}
//}
//
///////
// // 行移位
// ///
//static void shiftRows(int array[4][4]) {
//	int rowTwo[4], rowThree[4], rowFour[4];
//	int i;
//	for (i = 0; i < 4; i++) {
//		rowTwo[i] = array[1][i];
//		rowThree[i] = array[2][i];
//		rowFour[i] = array[3][i];
//	}
//
//	leftLoop4int(rowTwo, 1);
//	leftLoop4int(rowThree, 2);
//	leftLoop4int(rowFour, 3);
//
//	for (i = 0; i < 4; i++) {
//		array[1][i] = rowTwo[i];
//		array[2][i] = rowThree[i];
//		array[3][i] = rowFour[i];
//	}
//}
//
///////
// // 列混合要用到的矩阵
// ///
//static const int colM[4][4] = { 2, 3, 1, 1,
//	1, 2, 3, 1,
//	1, 1, 2, 3,
//	3, 1, 1, 2 };
//
//int GFMul2(int s) {
//	int result = s & 0x80;
//	s <<= 1;
//	if (result) {
//		s ^= 0x1B;
//	}
//
//	return s;
//}
////GF上的二元运算
//int GFMul(int u, int v) {
//	int p = 0;
//	for (int i = 0; i < 8; i++) {
//		if (u & 0x01) {
//			p ^= v;
//		}
//
//		v = GFMul2(v);
//
//		u >>= 1;
//	}
//
//	return p;
//}
////列混合
//static void mixColumns(int array[4][4]) {
//
//	int tempArray[4][4];
//	int i, j;
//	for (i = 0; i < 4; i++)
//		for (j = 0; j < 4; j++)
//			tempArray[i][j] = array[i][j];
//
//	for (i = 0; i < 4; i++)
//		for (j = 0; j < 4; j++) {
//			array[i][j] = GFMul(colM[i][0], tempArray[0][j]) ^ GFMul(colM[i][1], tempArray[1][j])
//				^ GFMul(colM[i][2], tempArray[2][j]) ^ GFMul(colM[i][3], tempArray[3][j]);
//		}
//}
//
///////
// // 参数 p: 明文的字符串数组。
// // 参数 plen: 明文的长度。
// // 参数 key: 密钥的字符串数组。
// ///
//void aes(char* p, int plen, char* key) {
//
//	int pArray[4][4];
//	int k, i;
//
//	KeyExpansion(key);//扩展密钥
//
//	for (k = 0; k < 16; k += 16) {
//		convertToIntArray(p, pArray);
//
//		addRoundKey(pArray, 0);//一开始的轮密钥加
//
//		for (i = 1; i < 10; i++) {
//
//			SubBytes(pArray);//字节代换
//
//			shiftRows(pArray);//行移位
//
//			mixColumns(pArray);//列混合
//
//			addRoundKey(pArray, i);
//
//		}
//
//		SubBytes(pArray);//字节代换
//
//		shiftRows(pArray);//行移位
//
//		addRoundKey(pArray, 10);
//
//		printArray(pArray);
//	}
//}
//
//int main() {
//	// 加密, 其中plain是明文字符数组， len是长度， key是密钥
//	//char *plain="00112233445566778899aabbccddeeff";
//	//char *key="000102030405060708090a0b0c0d0e0f";
//	int len = 32;
//	char* plain = new char[32];
//	char* key = new char[32];
//	for (int i = 0; i < 32; i++) {
//		cin >> key[i];
//	}
//	for (int i = 0; i < 32; i++) {
//		cin >> plain[i];
//	}
//	aes(plain, len, key);
//	system("pause");
//	return 0;
//}