#include <bits/stdc++.h>
using namespace std;

map<string,int> dict;
vector<int> solution(string msg) {
    vector<int> answer;
    int idx=1;
    char alpha='A';
    while(idx<=26){
        string tmp="";
        tmp+=alpha;
        dict[tmp]=idx;
        alpha++;
        idx++;
    }
    for(int i=0;i<msg.size();i++){
        string w="";
        int pos=i;
        w+=msg[pos];
        while(dict.find(w)!=dict.end()){
            w+=msg[++pos];
        }
        i=pos-1;
        dict[w]=idx++;
        w.pop_back();
        answer.push_back(dict[w]);
    }
    
    return answer;
}
