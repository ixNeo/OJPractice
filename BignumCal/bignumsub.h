#ifndef BIGNUMSUB_H
#define BIGNUMSUB_H

#include<iostream>
#include<cmath>
#include<string>
#include<iterator>
#include<algorithm>
#include "bignumadd.h"
using namespace std;


char cmpStr(string num1,string num2){
    char sign = '+';
    // 1.size; 2. equation
   if(num1.size()>num2.size()){
       sign = '+';
   }else if(num1.size()<num2.size()){
       sign = '-';
   }else{
       for(int i=0;i<num1.size();i++){
           if(num1[i]>num2[i]){
               sign = '+';  break;
           }else if(num1[i]<num2[i]){
               sign = '-';  break;
           }else{}
       }
   }
   return sign;
}
// big num sub
string bigNumSub(string num1,string num2){
    // get-sign
    char sign = cmpStr(num1,num2);

    // reverse
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());

    // standard-process data
    string bignum,smallnum,sumnum;
    if(sign=='+'){
        bignum = num1; smallnum = num2;
    }else{
        bignum = num2; smallnum = num1;
    }
    sumnum = bignum;

    // sub
    for(int i=0;i<smallnum.size();i++){
        int lowposVal = sumnum[i]-smallnum[i];
        int lowpos = i;
        sumnum[lowpos] = lowposVal+'0';
        while(lowposVal<0){
            sumnum[lowpos] = 10+lowposVal+'0';
//            if(lowpos+1>=sumnum.size()){
//                sumnum.append(1,'0');
//            }
            sumnum[lowpos+1] -= 1;
            lowposVal = sumnum[lowpos+1]-'0';
            lowpos += 1;
        }

    }

    // return
    reverse(sumnum.begin(),sumnum.end());
    cout <<  sign << sumnum << endl;
    return sumnum;
}
#endif // BIGNUMSUB_H
