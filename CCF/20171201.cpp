#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int sum = 1000;
const int nummax = 10000;
int a[sum];

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	sort(a,a+n);
	int res = 10000;
	for(int i=1;i<n;i++){
		int sub = abs(a[i] - a[i-1]); 
		if(sub<res){
			res = sub;
		}
	}
	cout << res << endl;
	return 0;
}
