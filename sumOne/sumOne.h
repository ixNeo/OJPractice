#ifndef SUMONE_H_INCLUDED
#define SUMONE_H_INCLUDED

/* 1
*  problem: 100--1300之间1的个数
*  int NumberOf1Between1AndN_Solution(int n);
*/
int sumOne(int n){
    int single = 0;
    int t = 0;
    int low = 0;
    int res = 0;
    for(int i=1;i<=n;i++){
        t = i;  low = t%10; single = 0;
        while(low|| t){
            if(low==1){
                single++;
                res++;
            }
            t /= 10; low = t%10;
        }
        cout << i << ": " << single << endl;
    }
    return res;
}

#endif // SUMONE_H_INCLUDED
