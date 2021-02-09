/*
 1. 유향 그래프
 2. 시작과 끝 비용 최소
 요구 : 최소비용, 도시 개수, 방문도시 순으로 출력
 풀이 : 다익스트라로 최단경로를 찾아가는 과정 중 이 경로를 추적할 수 있도록 해준다.
 */
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define endl "\n"
#define MAX 1001
#define INF 987654321
typedef pair<int, int> pii;
int n, m, s, e;
vector<pii> adj[MAX];
int trace[MAX];
int dist[MAX];
vector<int> ans;

void dijkstra(int start){
    dist[start]=0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({dist[start],start});
    while(!pq.empty()){
        int cost=pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        for(int i=0;i<adj[cur].size();i++){
            int nxt=adj[cur][i].first;
            int ncost=adj[cur][i].second;
            if(dist[nxt]>cost+ncost){
                dist[nxt]=cost+ncost;
                pq.push({dist[nxt], nxt});
                //만약 경로가 업데이트 된다면 추적경로도 업데이트
                trace[nxt]=0;
                trace[nxt]=cur;
            }
        }
    }
}

//경로 추적
void dfs(int end){
    if(end==s){
        ans.push_back(end);
        return;
    }
    ans.push_back(end);
    dfs(trace[end]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    for(int i=0;i<=n;i++){
        dist[i]=INF;
    }
    cin >> s >> e;
    dijkstra(s);
    dfs(e);
    cout << dist[e] << endl;
    cout << ans.size() << endl;
    for(int i=ans.size()-1;i>=0;i--){
        cout << ans[i] << " ";
    }
    
    return 0;
}
