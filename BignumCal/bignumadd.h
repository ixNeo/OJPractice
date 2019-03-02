#ifndef BIGNUMADD_H
#define BIGNUMADD_H
#include<iostream>
#include<cmath>
#include<string>
#include<iterator>
#include<algorithm>

using namespace std;
// big num add
string bigNumAdd(string num1,string num2){
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

    // add
    for(int i=0;i<smallnum.size();i++){
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
//    cout <<  sumnum << endl;
    return sumnum;
}
#endif // BIGNUMADD_H
