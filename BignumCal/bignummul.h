#ifndef BIGNUMMUL_H
#define BIGNUMMUL_H

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
    reverse(res.begin(),res.end());
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

    // multiply
    for(int i=0;i<smallnum.size();i++){
        string tmp = mulOnepos(bignum, smallnum[i]);
        tmp.append(i,'0');
//        cout << i << " : tmp after o-add: " << tmp << endl;
        sumnum = bigNumAdd(tmp,sumnum);
//        cout << i << " : sumnum " << sumnum << endl;
    }

//    reverse(sumnum.begin(),sumnum.end());
    cout <<  sumnum << endl;
    return sumnum;
}

#endif // BIGNUMMUL_H
