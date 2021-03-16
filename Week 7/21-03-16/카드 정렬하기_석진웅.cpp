#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n;

int main(){
    cin >> n;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        pq.push(a);
    }
    long long answer=0;
    if(pq.size()==1){
        cout << 0;
        return 0;
    }
    while(pq.size()>=2){
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        int c=a+b;
        answer+=c;
        if(pq.size()==0)break;
        pq.push(c);
    }
    cout << answer;
    return 0;
}
