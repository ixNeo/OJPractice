#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

/**
 * 쳲��������У�0,1,1,2��...
 * ������ⷽ�����ݹ�������洢 
*/

const int MAX = 10000;

int feibonaqie(int);
int arrayfeibo(int);
int combine(int);
int combineUnit(int*, int);

int main() {

	int res;
	int n, mode;
	cout << "����Ҫ��ڼ��0Ϊ�������� " << endl; cin >> n;
	cout <<  "�������÷������ţ�\n 1. �ݹ�\n 2. ����\n 3. �ۺ�" << endl; cin >> mode;
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

	cout << "�Ʋ��������е�" << n << "��Ϊ " << res << endl; 
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
		cout << "��" << i << "�" << a[i] << "\t"; 
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


