/*
 1. 무향 그래프
 2. 임의로 주어진 두 정점 반드시 통과
 3. 이동 여러번 가능.
 요구 : 두 정점을 거치며 최단 경로이동
 풀이 : 3번의 다익스트라를 사용해 문제 풀이.
 */
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 801
#define endl "\n"
typedef pair<int, int> pii;
int n,e,v1,v2;
vector<pii> adj[MAX];
//1번노드에서의 최단경로
int dist1[MAX];
//v1번 노드에서의 최단경로
int dist2[MAX];
//v2번 노드에서의 최단경로
int dist3[MAX];
int const INF=8000000;

void dijkstra(int s, int dist[]){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        int cost=pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        for(int i=0;i<adj[cur].size();i++){
            int nxt=adj[cur][i].first;
            int ncost=adj[cur][i].second;
            if(dist[nxt] > ncost+cost){
                dist[nxt]=ncost+cost;
                pq.push({dist[nxt],nxt});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> e;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    cin >> v1 >> v2;
    for(int i=1;i<=n;i++){
        dist1[i]=INF;
        dist2[i]=INF;
        dist3[i]=INF;
    }
    dijkstra(1,dist1);
    dijkstra(v1,dist2);
    dijkstra(v2,dist3);
    //1->v1->v2->n
    int case1=dist1[v1]+dist2[v2]+dist3[n];
    //1->v2->v1->n
    int case2=dist1[v2]+dist3[v1]+dist2[n];
    //그 중 최소거리가 답
    int ans=min(case1,case2);
    if(ans>=INF)cout << -1;
    else cout << ans;
    return 0;
}
