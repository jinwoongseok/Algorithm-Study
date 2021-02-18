#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
struct point{
    int x;
    int y;
    int dir;
    int cost;
};
int visited[25][25];
int n;

int bfs(vector<vector<int>> board){
    visited[0][0]=0;
    queue<point> q;
    point p;
    q.push({0,0,-1,0});
    while(!q.empty()){
        int x=q.front().x;
        int y=q.front().y;
        int dir=q.front().dir;
        int cost=q.front().cost;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            int nc;
            if(nx<0 || ny<0 || nx>=n || ny>=n)continue;
            if(board[ny][nx]==1)continue;
            //시작 지점이거나 진행방향이 같을 경우
            if(dir==-1 || dir==i){
                nc=cost+100;
            }
            //진행 방향이 다를 경우
            else if(dir!=i){
                nc=cost+600;
            }
            //visited 배열 안의 값이 코스트보다 크거나 같을경우 업데이트
            if(visited[ny][nx]>=nc){
                visited[ny][nx]=nc;
                q.push({nx,ny,i,nc});
            }
        }
    }
    //도착지점 반환
    return visited[n-1][n-1];
}

int solution(vector<vector<int>> board) {
    n=board[0].size();
    //INF값으로 초기화
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j]=INF;
        }
    }
    int answer = 0;
    answer=bfs(board);
    return answer;
}
