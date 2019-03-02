#ifndef FIRTONE_H_INCLUDED
#define FIRTONE_H_INCLUDED

int onlyPosStr(string str){
    map<char, vector<int>> res;
    for(int i=0;i<str.size();i++){
        char c = str[i];
        if(res.count(c)){
            res[c][1]++;
        }else {
            res[c].push_back(i);
            res[c].push_back(1);
        }
    }
    int pos = str.size();
    for(auto it=res.begin();it!=res.end();it++){
        if(it->second[1]==1){
            pos = min(pos, it->second[0]);
        }
    }
    if(pos==str.size()){
        return -1;
    }else{
            return pos;
    }

}

#endif // FIRTONE_H_INCLUDED
