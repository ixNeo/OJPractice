/* 3
* 丑数：只含质因子2, 3, 5 的数，如6, 8. 而14不是
* int number(int index)
*/

void uglyNum(int index){
       int p2=0, p3=0, p5=0;
       vector<int> res(index);
       res[0] =  1;
       int i=1;
       while(i<index){
        res[i] = min(res[p2]*2,min(res[p3]*3,res[p5]*5));
        if(res[i]==res[p2]*2){
            p2++;
        }
        if(res[i]==res[p3]*3){
            p3++;
        }
        if(res[i]==res[p5]*5){
            p5++;
        }
        cout << i << ": " << res[i] << endl;
        i++;
       }
       cout << res[index-1] << endl;
}

