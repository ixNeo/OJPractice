#include <iostream>
#include <algorithm>

using namespace std;


bool cmp1(int a, int b){
	return a<b;
}
int main(){
	int a[2] = {2,4};
	sort(a,a+2,cmp1);
	cout << a[0] << endl;
	cout << a[1] << endl; 
	return 0;
} 
