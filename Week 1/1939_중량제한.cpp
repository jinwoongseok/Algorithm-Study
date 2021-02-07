#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 10001
int pr[MAX];
int arr[MAX];
int n, m;
struct info{
    int a;
    int b;
    int c;
};
vector<info> adj;
int s, e;

bool comp(info& a, info& b){
    return a.c > b.c;
}

int findf(int a){
    if(a==pr[a])return a;
    pr[a]=findf(pr[a]);
    return pr[a];
}

void unionf(int a, int b){
    int roota=findf(a);
    int rootb=findf(b);
    pr[rootb]=roota;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj.push_back({a,b,c});
    }
    cin >> s >> e;
    for(int i=1;i<n;i++){
        pr[i]=i;
    }
    sort(adj.begin(),adj.end(),comp);
    int ans=0;
    for(int i=0;i<adj.size();i++){
        int a=adj[i].a;
        int b=adj[i].b;
        int c=adj[i].c;
        if(findf(a)!=findf(b)){
            unionf(a,b);
            if(findf(s)==findf(e)){
                ans=c;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
