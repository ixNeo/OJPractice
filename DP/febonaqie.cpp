#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

/**
 * 斐波那契数列：0,1,1,2，...
 * 两种求解方法：递归与数组存储 
*/

const int MAX = 10000;

int feibonaqie(int);
int arrayfeibo(int);
int combine(int);
int combineUnit(int*, int);

int main() {

	int res;
	int n, mode;
	cout << "输入要求第几项（0为基数）： " << endl; cin >> n;
	cout <<  "输入所用方法代号：\n 1. 递归\n 2. 数组\n 3. 综合" << endl; cin >> mode;
	switch(mode){
		case 1: 	
			res = feibonaqie(n); 
			break;
		case 2:
			res = arrayfeibo(n);
			break;
		case 3:
			res = combine(n);
	}

	cout << "菲波那切数列第" << n << "项为 " << res << endl; 
	return 0;
} 

int feibonaqie(int n){
	if(n==0){
		return 0;
	}else if(n==1){
		return 1;
	}else{
		return feibonaqie(n-1) + feibonaqie(n-2); 
	}
}

int arrayfeibo(int n){
	int  a[MAX];
	a[0] = 0; a[1] = 1;
	for(int i=2;i<=n;i++){
		a[i] = a[i-1] + a[i-2];
		cout << "第" << i << "项：" << a[i] << "\t"; 
	}
	cout << endl;
	return a[n];
}

int combine(int n){
	int a[MAX];
	memset(a,-1,sizeof(int)*MAX);
	a[0] = 0; a[1] = 1;
	return combineUnit(a,n);
} 

int combineUnit(int* a, int n){
	if(a[n]!=-1){
		return a[n];
	}else {
		return combineUnit(a,n-1) + combineUnit(a,n-2);
	}
}


