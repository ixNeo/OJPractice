#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int WEIGHT = 10;
int main(){
	int values[4] = {10,40,30,50};
	int weight[4] = {5,4,6,3};
	int d[5][11];
	for(int i=0;i<5;i++){
		d[i][0] = 0;
	}
	for(int i=0;i<11;i++){
		d[0][i] = 0;
	}

	for(int i=1;i<5;i++){
		for(int j=1;j<11;j++){
			d[i][j] = d[i-1][j];
			if(j>=weight[i])
				d[i][j] = max(d[i-1][j],d[i-1][j-weight[i]]+values[i]);
		}
	}
	int maxn = 0;
	for(int i=0;i<11;i++)
		if(maxn<d[5][i])
			maxn = d[5][i];
	cout << maxn << endl;
	return 0;
}