#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

/**
* 最长公共子串
* 二维矩阵的行和列分别表示结束查询的位置
* 输出公共子串的长度
* bug解决：
	1. 申请空间时行列弄混，空间大小不对
	2. 释放空间时大小不对
* 额外知识点：
	1. string输入：
		1. cin：空格也是分隔符
		2. getline(cin,str,dim)， 默认分隔符是'\n'
*/

int LCS(string a, string b);

int main() {
	string a, b;
	cout << "输入两个字符串：（enter键结束）" << endl;
	cin >> a >> b;
	int res = LCS(a, b);
	cout << "最长公共子串的长度为： " << res << endl;
	return 0;
}

int LCS(string a, string b) {

	int a_len = a.length(), b_len = b.length();

	// 申请空间
	int** d = new int*[a_len];
	for (int i = 0; i<a_len; i++) {
		d[i] = new int[b_len];
	}

	// 初值
	for (int i = 0; i<b_len; i++) {
		if (a[0] == b[i]) {
			d[0][i] = 1;
		}
		else {
			d[0][i] = 0;
		}
	}

	for (int i = 0; i<a_len; i++) {
		if (b[0] == a[i]) {
			d[i][0] = 1;
		}
		else {
			d[i][0] = 0;
		}
	}

	// 迭代
	for (int i = 1; i<a_len; i++) {
		for (int j = 1; j<b_len; j++) {
			if (a[i] == b[j]) {
				d[i][j] = d[i - 1][j - 1] + 1;
			}
			else {
				d[i][j] = 0;
			}
		}
	}

	// 打印表格
	int res = 0;
	cout << "表格如下： " << endl;
	for (int i = 0; i<a_len; i++) {
		for (int j = 0; j<b_len; j++) {
			res = max(res, d[i][j]);
			cout << d[i][j] << '\t';
		}
		cout << endl;
	}

	// 释放空间
	for (int i = 0; i < a_len; i++) {
		delete[] d[i];
	}
	delete[] d;

	return res;
}