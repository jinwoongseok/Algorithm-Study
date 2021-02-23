#include <bits/stdc++.h>
using namespace std;

bool check[100001];

bool comp(string a, string b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> v;
    for(int i=1;i<s.size()-1;i++){
        if(s[i]=='{'){
            string str="";
            i++;
            while(s[i]!='}'){
                str+=s[i];
                i++;
            }
            v.push_back(str);
        }
    }
    sort(v.begin(), v.end(), comp);
    for(int i=0;i<v.size();i++){
        vector<int> candidate;
        istringstream ss(v[i]);
        string buf;
        while(getline(ss, buf, ',')){
            candidate.push_back(stoi(buf));
        }
        for(int j=0;j<candidate.size();j++){
            if(check[candidate[j]]==false){
                check[candidate[j]]=true;
                answer.push_back(candidate[j]);
            }
        }
    }
    return answer;
}
