#ifndef MINARRAYNUM_H_INCLUDED
#define MINARRAYNUM_H_INCLUDED

/*  2
* 数字数组，求最小组合
* 函数 string PrintMinNumber(vector<int> numbers)
* 思路：直接改变cmp函数，不用字典序，相邻的两个数字，正序和倒序求和比较
* trick: cmp函数规定了顺序，没有规定具体排序算法
*/
bool cmp(int a, int b){
    string s1 = to_string(a)+to_string(b);
    string s2 = to_string(b) + to_string(a);
    return s1<s2;
}

string minArrayNum(vector<int> numbers){
    string res;
    sort(numbers.begin(),numbers.end(), cmp);
    for(int i=0;i<numbers.size();i++){
        cout << numbers[i] << endl;
    }
    return res;
}


#endif // MINARRAYNUM_H_INCLUDED
