#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(int a, int b){
    return a>b;
}
int n;
vector<int> v1;
vector<int> v2;

int main(){
    cin >> n;
    long long answer=0;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        if(a>1)v1.push_back(a);
        else if(a==1) answer+=1;
        else v2.push_back(a);
    }
    sort(v1.begin(),v1.end(),comp);
    for(int i=0;i<v1.size();i++){
        if(i<v1.size()-1){
            answer+=v1[i]*v1[i+1];
            i++;
        }
        else answer+=v1[i];
    }
    sort(v2.begin(), v2.end());
    for(int i=0;i<v2.size();i++){
        if(i<v2.size()-1){
            answer+=v2[i]*v2[i+1];
            i++;
        }
        else answer+=v2[i];
    }
    cout << answer;
    return 0;
}
