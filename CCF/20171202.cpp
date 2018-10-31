/*模拟游戏
 * tricks: 1. memset(*p, value, sizeof(*p) 
 			2. 两个变量：一个用于不断循环模运算推进同学编号，一个报号 
 			3. 循环退出条件：上次报号的不是自己，否则将淘汰所有人 
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
				cout << i%n+1 << " 淘汰 " << " 报数 " << t+1 << endl; 
			}
			if(flag[i%n])
				cout << "   "<< i%n+1 << " 报数 " << t+1 << endl; 
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
