#include <bits/stdc++.h>
using namespace std;

map<string, set<string>> res;
set<string> visited;
set<set<string>> ans;
int result;
int n;

struct trie{
    bool isEnd;
    trie* nxt[36];
    trie(){
        for(int i=0;i<36;i++){
            nxt[i]=NULL;
        }
        isEnd=false;
    }
    ~trie(){
        for(int i=0;i<36;i++){
            delete nxt[i];
        }
    }
    void insert(string str){
        trie* cur=this;
        for(int i=0;i<str.size();i++){
            int idx;
            if(str[i]>='0' && str[i]<='9'){
                idx=str[i]-'0';
            }
            else{
                idx=str[i]-'W';
            }
            if(cur->nxt[idx]==NULL){
                cur->nxt[idx]=new trie();
            }
            cur=cur->nxt[idx];
        }
        cur->isEnd=true;
    }
    void find(string str, trie* cur, int pos, string origin){
        for(int i=pos;i<str.size();i++){
            int idx;
            if(str[i]=='*'){
                bool err=false;
                for(int j=0;j<36;j++){
                    string ns=str;
                    if(j>=0 && j<=9){
                        ns[i]=j+'0';
                    }
                    if(j>=10 && j<=35){
                        ns[i]=j+'W';
                    }
                    if(cur->nxt[j]!=NULL){
                        find(ns, cur->nxt[j], i+1, origin);
                        err=true;
                    }
                }
                return;
            }
            else if(str[i]>='0' && str[i]<='9'){
                idx=str[i]-'0';
                if(cur->nxt[idx]==NULL){
                    return;
                }
                cur=cur->nxt[idx];
            }
            else{
                idx=str[i]-'W';
                if(cur->nxt[idx]==NULL){
                    return;
                }
                cur=cur->nxt[idx];
            }
        }
        if(cur->isEnd){
            res[origin].insert(str);
        }
    }
};

void dfs(int cur, vector<string> banned_id){
    if(visited.size()==n){
        ans.insert(visited);
    }
    if(cur==n-1)return;
    string nstr=banned_id[cur+1];
    for(auto i : res[nstr]){
        if(visited.find(i)==visited.end()){
            visited.insert(i);
            dfs(cur+1, banned_id);
            visited.erase(i);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    n=banned_id.size();
    trie* root=new trie();
    for(int i=0;i<user_id.size();i++){
        root->insert(user_id[i]);
    }
    for(int i=0;i<banned_id.size();i++){
        root->find(banned_id[i],root,0,banned_id[i]);
    }
    string str=banned_id[0];
    for(auto& i : res[str]){
        if(visited.find(i)==visited.end()){
            visited.insert(i);
            dfs(0, banned_id);
            visited.erase(i);
        }
    }
    answer=ans.size();
    return answer;
}
