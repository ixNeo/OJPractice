#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

/**
* 最长公共子序列
* 矩阵多一行一列，为0。 从1开始进行是否a[i]==b[i]的判断
*/

int LCS(string a, string b);

int main() {
	string a, b;
	cout << "最长公共子序列： \n*********************" << endl;
	cout << "输入两个字符串：（enter键结束）" << endl;
	cin >> a >> b;
	int res = LCS(a, b);
	cout << "******************\n最长公共子序列的长度为： " << res << endl;
	return 0;
}

int LCS(string a, string b) {

	int a_len = a.length(), b_len = b.length();

	// 申请空间
	int** d = new int*[a_len+1];
	for (int i = 0; i<a_len+1; i++) {
		d[i] = new int[b_len+1];
	}

	// 初值
	for (int i = 0; i<b_len+1; i++) {
		d[0][i] = 0;
	}

	for (int i = 0; i<a_len+1; i++) {
		d[i][0] = 0;
	}

	// 迭代
	for (int i = 1; i<a_len+1; i++) {
		for (int j = 1; j<b_len+1; j++) {
			if (a[i] == b[j]) {
				d[i][j] = d[i - 1][j - 1] + 1;
			}
			else {
				d[i][j] = max(d[i-1][j],d[i][j-1]); 
			}
		}
	}

	// 打印表格
	int res = 0;
	int row=0, col=0;
	cout << "******************\n表格如下： " << endl;
	for (int i = 0; i<a_len+1; i++) {
		for (int j = 0; j<b_len+1; j++) {
			if(res<d[i][j]){
				res = d[i][j];
				row = i; col = j;
			}
			cout << d[i][j] << '\t';
		}
		cout << endl;
	}

	// 打印最长公共子序列
	int i=row, j=col;
	string lcs;
	while(i>=1 && j>=1 && d[i][j]>0){
		lcs += a[i-1];
		if(d[i][j]-d[i-1][j-1]==1){
			i--;j--;
		}else if(d[i][j]==d[i-1][j]){
			i--;
		}else{
			j--;
		}
	}
	reverse(lcs.begin(),lcs.end());
	cout << "******************\n最长公共子序列为：" << lcs << endl;

	// 释放空间
	for (int i = 0; i < a_len+1; i++) {
		delete[] d[i];
	}
	delete[] d;

	return res;
}