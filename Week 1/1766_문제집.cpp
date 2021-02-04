#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 32001
int n, m;
int indegree[MAX];
vector<int> adj[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        //간선 연결
        adj[a].push_back(b);
        //해당 노드 차수 업데이트
        indegree[b]++;
    }
    //노드 넘버가 작은 순으로 문제를 풀어야함
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=1;i<=n;i++){
        //차수가 0인것부터 시작
        if(indegree[i]==0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        int cur=pq.top();
        pq.pop();
        cout << cur << " ";
        for(int i=0;i<adj[cur].size();i++){
            int nxt=adj[cur][i];
            //차수 하나 제거
            indegree[nxt]--;
            //만약 차수가 0이되면 우선순위큐에 넣는다.
            if(indegree[nxt]==0){
                pq.push(nxt);
            }
        }
    }
    return 0;
}
