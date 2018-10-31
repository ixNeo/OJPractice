/*ģ����Ϸ
 * tricks: 1. memset(*p, value, sizeof(*p) 
 			2. ����������һ�����ڲ���ѭ��ģ�����ƽ�ͬѧ��ţ�һ������ 
 			3. ѭ���˳��������ϴα��ŵĲ����Լ���������̭������ 
*/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int N = 10000;
bool flag[N];

int main(){
	int n,k,t,pre;
	t = 0;
	pre = 1000;
	
	cin >> n >> k;
	memset(flag,true,sizeof(flag));
	for(int i=0;i<10000;i++){
		
		if(flag[i%n]){
			if(i%n==pre){
				break;
			}
			if((t+1)%k==0 || (t+1)%10==k){
				flag[i%n] = false;
				cout << i%n+1 << " ��̭ " << " ���� " << t+1 << endl; 
			}
			if(flag[i%n])
				cout << "   "<< i%n+1 << " ���� " << t+1 << endl; 
			t++;
			
			pre = i%n;
		}
	}
	for(int i=0;i<n;i++){
		if(flag[i]){
			cout << i+1 << "    ";
		}
	}
	return 0;
} 
