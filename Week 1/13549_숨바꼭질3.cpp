#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 100001
#define endl "\n"
typedef pair<int, int> pii;
bool visited[MAX];
int n, k;

//갈 수 있는가?
bool check(int cur){
    if(cur < 0 || cur >= MAX || visited[cur])return false;
    return true;
}

int bfs(int n, int k){
    int res=987654321;
    //first=시간, second=현재 위치
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,n});
    visited[n]=true;
    while(!pq.empty()){
        int cnt=pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        if(cur==k){
            return cnt;
        }
        if(check(cur*2)){
            visited[cur*2]=true;
            pq.push({cnt,cur*2});
        }
        if(check(cur-1)){
            visited[cur-1]=true;
            pq.push({cnt+1,cur-1});
        }
        if(check(cur+1)){
            visited[cur+1]=true;
            pq.push({cnt+1,cur+1});
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    cout << bfs(n,k);
    return 0;
}
