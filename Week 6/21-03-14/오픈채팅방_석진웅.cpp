#include <bits/stdc++.h>
using namespace std;

typedef pair<bool, string> pbs;
map<string, string> m;
vector<pbs> print;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    for(int i=0;i<record.size();i++){
        istringstream ss(record[i]);
        string buf;
        vector<string> v;
        while(getline(ss,buf,' ')){
            v.push_back(buf);
        }
        if(v[0]=="Enter"){
            m[v[1]]=v[2];
            print.push_back({true,v[1]});
        }
        else if(v[0]=="Leave"){
            print.push_back({false,v[1]});
        }
        else{
            m[v[1]]=v[2];
        }
    }
    for(int i=0;i<print.size();i++){
        if(print[i].first==true){
            string str="";
            str+=m[print[i].second];
            str+="님이 들어왔습니다.";
            answer.push_back(str);
        }
        else{
            string str="";
            str+=m[print[i].second];
            str+="님이 나갔습니다.";
            answer.push_back(str);
        }
    }
    return answer;
}
