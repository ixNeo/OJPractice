#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

/* 归并排序
* 1. iteration
* 2. recurisive
* paragram: array(entire) and start and end
*/
void mergeSort(vector<int>& array, int start, int end){
	if(start>=end){
		return ;
	}
	int mid = (start+end)/2;
	mergeSort(array,start,mid);
	mergeSort(array,mid+1, end);

	vector<int> leftarr (array.begin()+start, array.begin()+mid);
	vector<int> rightarr(array.begin()+mid, array.begin()+end);
	int pl = 0, pr = 0;

	leftarr.insert(leftarr.end(),numeric_limits<int>::max());
	rightarr.insert(leftarr.end(),numeric_limits<int>::max());	
	for(int i=start;i<end;i++){
		if(leftarr[pl]<rightarr[pr]){
			array[i] = leftarr[pl++];
		}else {
			array[i] = rightarr[pr++];
		}
	}
}

void showarr(vector<int> arr){
	for(int i=0;i<arr.size();i++){
		cout << arr[i] << "\t" << endl;
	}
}
int main(){
	vector<int> a({4,3,2,8,9});
	mergeSort(a,0,a.size());
	showarr(a);
}