#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

/*������Ϊ���ʸ�������
 * ��ʼ�Ͱ����б�Ŷ����ڶ����У�������pop, �������ʸ��ٴ�ѹ��*/
int main(){
	queue<int> q;
	int n,k,t = 1;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		q.push(i);
	} 
	while(q.size()>1){
		if(t%k==0 || t%10==k){
			q.pop();			
		}else{
			q.push(q.front());
			q.pop();
		}
		t++;
	}
	cout << q.front();
	return 0;
} 
