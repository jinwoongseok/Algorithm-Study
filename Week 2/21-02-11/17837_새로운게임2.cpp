/*
 구현 문제이다. 팁을 주자면 다음과 같다.
 1. 각 맵에 대해서 현재 위치에 어떻게 말들이 존재하는지 확인할 수 있는 string타입 벡터를 사용한다.
 2. 위치 정보와 방향 정보를 갖는 말에 대한 구조체 배열을 사용한다.
 3. 우선순위를 벽과 파란색 영역 -> 흰색 or 빨간색 영역순으로 판단한다.
 */
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int n, k;
int map[13][13];
struct horse{
    int x;
    int y;
    int dir;
};
int dx[]={0,1,-1,0,0};
int dy[]={0,0,0,-1,1};
horse h[11];
vector<string> info[13][13];

int change_dir(int d){
    if(d==1)return 2;
    else if(d==2)return 1;
    else if(d==3)return 4;
    else return 3;
}

int solve(){
    int turn=0;
    while(true){
        turn++;
        if(turn>1000)return -1;
        for(int i=1;i<=k;i++){
            int x=h[i].x;
            int y=h[i].y;
            int d=h[i].dir;
            string num=to_string(i);
            //현재 말부터 위에 존재하는 말까지 더미로 만듬
            vector<string> dummy;
            int pos;
            for(int j=0;j<info[y][x].size();j++){
                string str=info[y][x][j];
                if(num==str){
                    pos=j;
                    break;
                }
            }
            dummy.assign(info[y][x].begin()+pos,info[y][x].end());
            info[y][x].erase(info[y][x].begin()+pos, info[y][x].end());
            int nx=x+dx[d];
            int ny=y+dy[d];
            if((nx<1 || ny<1 || nx>n || ny>n) || map[ny][nx]==2){
                d=change_dir(d);
                nx=x+dx[d];
                ny=y+dy[d];
                //양 방향 모두 막혀있다면
                if((nx<1 || ny<1 || nx>n || ny>n) || map[ny][nx]==2){
                    nx=x;
                    ny=y;
                    h[i].dir=d;
                    for(int j=0;j<dummy.size();j++){
                        int idx=stoi(dummy[j]);
                        h[idx].x=nx;
                        h[idx].y=ny;
                        info[ny][nx].push_back(dummy[j]);
                    }
                    if(info[ny][nx].size()>=4)return turn;
                    continue;
                }
            }
            //흰 영역
            if(map[ny][nx]==0){
                h[i].dir=d;
                for(int j=0;j<dummy.size();j++){
                    int idx=stoi(dummy[j]);
                    h[idx].x=nx;
                    h[idx].y=ny;
                    info[ny][nx].push_back(dummy[j]);
                }
            }
            //빨간 영역
            if(map[ny][nx]==1){
                h[i].dir=d;
                for(int j=dummy.size()-1;j>=0;j--){
                    int idx=stoi(dummy[j]);
                    h[idx].x=nx;
                    h[idx].y=ny;
                    info[ny][nx].push_back(dummy[j]);
                }
            }
            if(info[ny][nx].size()>=4)return turn;
        }
            
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> map[i][j];
        }
    }
    for(int i=1;i<=k;i++){
        int y, x, dir;
        cin >> y >> x >> dir;
        h[i].x=x;
        h[i].y=y;
        h[i].dir=dir;
        info[y][x].push_back(to_string(i));
    }
    cout << solve();
    return 0;
}
