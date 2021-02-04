#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 500
#define endl "\n"
int map[MAX][MAX];
bool visited[MAX][MAX];
int m, n;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int result;
int dp[MAX][MAX];

int dfs(int x, int y){
    if(x==n-1 && y==m-1){
        return 1;
    }
    int& ret=dp[y][x];
    if(ret!=-1)return ret;
    ret=0;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0 || ny<0 || nx>=n || ny>=m)continue;
        if(map[ny][nx]>=map[y][x])continue;
        ret += dfs(nx,ny);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(0,0);
    return 0;
}
