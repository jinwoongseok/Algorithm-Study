#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
int n;
string map[100];
bool visited[100][100];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};


void normal(int sx, int sy){
    visited[sy][sx]=true;
    queue<pii> q;
    q.push({sx,sy});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        char cur=map[y][x];
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || ny<0 || nx >=n || ny >= n)continue;
            if(visited[ny][nx])continue;
            if(map[ny][nx]!=cur)continue;
            visited[ny][nx]=true;
            q.push({nx,ny});
        }
    }
}

void red_green(int sx, int sy){
    visited[sy][sx]=true;
    queue<pii> q;
    q.push({sx,sy});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        char cur=map[y][x];
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || ny<0 || nx >=n || ny >= n)continue;
            if(visited[ny][nx])continue;
            if(cur=='B'){
                if(map[ny][nx]!=cur)continue;
            }
            else{
                if(map[ny][nx]=='B')continue;
            }
            visited[ny][nx]=true;
            q.push({nx,ny});
        }
    }
}

void solution(){
    int res1=0;
    int res2=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]==false){
                normal(j,i);
                res1++;
            }
        }
    }
    memset(visited,0,sizeof(visited));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]==false){
                red_green(j,i);
                res2++;
            }
        }
    }
    cout << res1 << endl;
    cout << res2 << endl;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> map[i];
    }
    solution();
    return 0;
}
