#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    string bomb;
    cin >> str;
    cin >> bomb;
    vector<char> v;
    for(int i=0;i<str.size();i++){
        v.push_back(str[i]);
        if(v.size()>=bomb.size()){
            int cnt=0;
            int vidx=v.size()-1;
            int bidx=bomb.size()-1;
            while(cnt<bomb.size()){
                if(v[vidx]==bomb[bidx]){
                    vidx--;
                    bidx--;
                    cnt++;
                }
                else{
                    break;
                }
            }
            if(cnt==bomb.size()){
                while(cnt--){
                    v.pop_back();
                }
            }
        }
    }
    if(v.size()==0){
        cout << "FRULA";
    }
    else{
        for(int i=0;i<v.size();i++){
            cout << v[i];
        }
    }
    return 0;
}
