#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

/**
 * 问题描述：背包问题
 * bug解决： 下标不一致问题， value和d, 因为d矩阵多加了一行一列
*/

// 常量和函数声明
const int WEIGHT = 10;
int bagSolve(int*, int*, int num);


int main(){
	int values[4] = {10,40,30,50};
	int weight[4] = {5,4,6,3};
	int num = 4;
	int max_value = bagSolve(weight, values, num);
	cout << "背包问题（最大重量为10的情况下），价值最大为： " 
		 << max_value << endl;
	return 0;
}

int bagSolve(int* weight, int* values, int num){
	// 申请二维矩阵空间
	int** d = new int*[num+1];
	for(int i=0;i<=num;i++){
		d[i] = new int[WEIGHT+1];
	}

	// 初始化多出来的一行一列
	for(int i=0;i<=num;i++){
		d[i][0] = 0;
	}

	for(int i=0;i<=WEIGHT;i++){
		d[0][i] = 0;
	}

	// 迭代
	for(int i=1;i<=num;i++){
		for(int j=1;j<=WEIGHT;j++){
			d[i][j] = d[i-1][j];
			if(j>=weight[i-1]){
				d[i][j] = max(d[i-1][j], values[i-1]+d[i-1][j-weight[i-1]]);
			}
		}
	}

	// 求解最大值
	int res = 0;
	for(int i=0;i<=WEIGHT;i++){
		res = max(res, d[num][i]);
	}

	// 输出矩阵
	cout << "输出矩阵: " << endl;
	for(int i=0;i<=num;i++){
		for(int j=0;j<=WEIGHT;j++){
			cout << d[i][j] << '\t';
		}
		cout << endl;
	}

 	for(int i=0;i<=num;i++){
 		delete[] d[i];
 	}
 	delete[] d;

	return res;
}
