#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

// 本文件中的所有函数只提供一位数四则运算

// 后缀计算
char calPost(string s){
	double res = 0;
	stack<char> store;
	string::iterator it = s.begin();
	for(;it!=s.end();it++){
		
		if(*it>='0' && *it<='9'){
			store.push(*it);
//			cout << "digit" << *it << endl;
		}
		else{
			char op = *it; 
			char num2 = store.top()-'0';store.pop();
//			cout << num2 << endl;
			char num1 = store.top()-'0';store.pop();
//			cout << num1 << endl;
			switch(op){
				case '+' : store.push(num1+num2+'0');break;
				case '-' : store.push(num1-num2+'0'); break;
				case '*' : store.push(num1*num2+'0'); break;
				case '/' : store.push(num1/num2+'0'); break;
				default : ;
			}
		}
	}
	if(store.size()==1)
		return store.top();
	else{
		cout << "wrong" << endl;
		return '0';
	}
}


// 中缀变后缀
stack<char> inToPost(string ins){
	map<char,int> priority;
	priority.insert(make_pair('+',1));
	priority.insert(make_pair('-',1));
	priority.insert(make_pair('*',2));
	priority.insert(make_pair('/',2));
	stack<char> opStack;
	stack<char> resStack;
	for(int i=0;i<ins.size();i++){
		if(resStack.empty()
			|| (ins[i]<='9' && ins[i]>='0') ){			
			resStack.push(ins[i]);
		}else if(opStack.empty()
			||ins[i]=='('
			|| (ins[i]!=')' && opStack.top()=='(') 
			||priority[ins[i]]>priority[opStack.top()] ){
			opStack.push(ins[i]);
		}else if(ins[i]==')' ){
			while(opStack.top()!='('){
				resStack.push(opStack.top());
				opStack.pop();
			}
			opStack.pop();
		}else if(priority[ins[i]]<=priority[opStack.top()]){
			resStack.push(opStack.top());
			opStack.pop();
			opStack.push(ins[i]);
		}
	}
	while(!opStack.empty()){
		resStack.push(opStack.top());
		opStack.pop();
	}
	return resStack;
}


// 输出栈内容
void showStack(stack<char> in){
	while(!in.empty()){
		cout << in.top() << endl;
		in.pop();
	}
}


// 计算中缀
char calIn(string ins){
	map<char,int> priority;
	priority.insert(make_pair('+',1));
	priority.insert(make_pair('-',1));
	priority.insert(make_pair('*',2));
	priority.insert(make_pair('/',2));
	stack<char> opStack;
	stack<char> resStack;
	for(int i=0;i<ins.size();i++){
		if(resStack.empty()
			|| (ins[i]<='9' && ins[i]>='0') ){			
			resStack.push(ins[i]);
		}else if(opStack.empty()
			||ins[i]=='('
			|| (ins[i]!=')' && opStack.top()=='(') 
			||priority[ins[i]]>priority[opStack.top()] ){
			opStack.push(ins[i]);
		}else if(ins[i]==')' ){
			while(opStack.top()!='('){
				char num2 = resStack.top()-'0';resStack.pop();
				char num1 = resStack.top()-'0';resStack.pop();
				switch(opStack.top()){
					case '+' : resStack.push(num1+num2+'0');break;
					case '-' : resStack.push(num1-num2+'0'); break;
					case '*' : resStack.push(num1*num2+'0'); break;
					case '/' : resStack.push(num1/num2+'0'); break;
					default : ;
				}
				opStack.pop();
			}
			opStack.pop();
		}else if(priority[ins[i]]<=priority[opStack.top()]){
			char num2 = resStack.top()-'0';resStack.pop();
			char num1 = resStack.top()-'0';resStack.pop();
			switch(opStack.top()){
				case '+' : resStack.push(num1+num2+'0');break;
				case '-' : resStack.push(num1-num2+'0'); break;
				case '*' : resStack.push(num1*num2+'0'); break;
				case '/' : resStack.push(num1/num2+'0'); break;
				default : ;
			}
			opStack.pop();
			opStack.push(ins[i]);
		}
	}
	while(!opStack.empty()){
		char num2 = resStack.top()-'0';resStack.pop();
		char num1 = resStack.top()-'0';resStack.pop();
		switch(opStack.top()){
			case '+' : resStack.push(num1+num2+'0');break;
			case '-' : resStack.push(num1-num2+'0'); break;
			case '*' : resStack.push(num1*num2+'0'); break;
			case '/' : resStack.push(num1/num2+'0'); break;
			default : ;
		}
		opStack.pop();
	}
	if(resStack.size()==1)
		return resStack.top();
	else{
		cout << "resStack more than 1 " << endl;
		return resStack.top();
	}
}

int main(){
	// 测试后缀表达式的计算
/*	string s = "123+4*+5-";
	double res = calPost(s)-'0';
	cout << res << endl;
	return 0;*/
	

	// 测试中缀转后缀
/*	string s = "1+((2+3)*4)-5";
	stack<char> res = inToPost(s);
	showStack(res);*/

	// 测试中缀计算1+((2+3)*4)-5
	string s = "1+((2+3)*4)-5";
	double res = calIn(s)-'0';
	cout << res << endl;
	return 0;
}

