#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iterator>
#include <algorithm>


using namespace std;

bool match(const string& s, const string& t){
	int size_s=0,size_t=0;
	bool flag = false;
	while(size_s<s.size() && size_t<t.size()){
		if(s[size_s]==t[size_t]){
			size_s++;size_t++;
		}else if(t[size_t++]=='<'){
			if(t[size_t]=='i' && isdigit(s[size_s])){
//				cout << "进入数字判断";
				while(isdigit(s[size_s])){
					cout << s[size_s];
					size_s++;
				}
				cout << " ";
				size_t+=4;
			}else if(t[size_t]=='s'){
				while(s[size_s]!='/'){
					cout << s[size_s];
					size_s++;
				}
				cout << " ";
				size_t+=4;				
			}else if(t[size_t]=='p'){
//				cout << "直接正确" ;
				return true;
			}else{
//				cout << "< 不符合"; 
				return false;
			}			
		}else{
			return false;
		}
	}
	return true;
}


/* url映射 */
int main(){
	map<string,string> v;
	v.insert(make_pair("/articles/2003/","special_case_2003"));
	v.insert(make_pair("/articles/<int>/<int>/", "month_archive"));
	v.insert(make_pair("/articles/<int>/<int>/<str>/","article_detail"));
	v.insert(make_pair("/articles/<int>/","year_archive"));
	v.insert(make_pair("/static/<path>","static_serve"));
	
	vector<string> in;
	in.push_back("/articles/2004/");
	in.push_back("/articles/1985/09/aloha/");
	in.push_back("/articles/hello/");
	in.push_back("/static/js/jquery.js"); 
	map<string,string>::iterator itv;
	vector<string>::iterator itin;
	/*
	for(itv=v.begin();itv!=v.end();itv++){
		cout << itv->first << "    " << itv->second << endl;
	}
	*/
	bool flag = true;
	for(itin=in.begin();itin!=in.end();itin++){
		flag = true;
		for(itv=v.begin();itv!=v.end();itv++){
			if(match(*itin,itv->first)){
				flag = false;
				cout << "输入串" << *itin << "    匹配名称" <<itv->second << endl;
//				break;
			}
		}
		if(flag){
			cout << "404 not found" << endl;
		}
	}
	
	return 0;
}
