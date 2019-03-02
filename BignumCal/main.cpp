#include<iostream>
#include<cmath>
#include<string>
#include<iterator>
#include<algorithm>
#include "bignumadd.h"
using namespace std;

string mulOnepos(string bignum, char smallOne){
    string res;
    int curNum=0, lowNum=0, highNum=0;

//    reverse(bignum.begin(),bignum.end());

    for(int i=0;i<bignum.size();i++){
        curNum = highNum + (bignum[i]-'0')*(smallOne-'0');
        lowNum = curNum % 10;
        if(curNum>=10){
            highNum = curNum / 10;
        }else{
            highNum = 0;
        }
        res.append(1,lowNum+'0');
    }
    if(highNum!=0){
        res.append(1,highNum+'0');
    }
//    reverse(res.begin(),res.end());
    return res;
}

// big num multiply
string bigNumMul(string num1,string num2){
    // reverse
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());

    // standard-process data
    string bignum,smallnum,sumnum;
    if(num1.size()>num2.size()){
        bignum = num1; smallnum = num2;
    }else{
        bignum = num2; smallnum = num1;
    }
    sumnum = bignum;

    // multiply
    for(int i=0;i<smallnum.size();i++){
        string tmp;
        tmp = mulOnepos(bignum, smallnum[i]);
        int lowposVal = smallnum[i]-'0'+sumnum[i]-'0';
        int lowpos = i;
        sumnum[lowpos] = lowposVal+'0';
        while(lowposVal>9){
            sumnum[lowpos] = lowposVal+'0'-10;
            if(lowpos+1>=sumnum.size()){
                sumnum.append(1,'0');
            }
            sumnum[lowpos+1] += 1;
            lowposVal = sumnum[lowpos+1]-'0';
            lowpos += 1;
        }

    }

    // return
    reverse(sumnum.begin(),sumnum.end());
    cout <<  sumnum << endl;
    return sumnum;
}

int main(){
    string num1,num2,sumnum;
    cin >> num1 >> num2;
    sumnum = bigNumMul(num1,num2);
//    cout << mulOnepos(num1,'8') << endl;
    return 0;
}
