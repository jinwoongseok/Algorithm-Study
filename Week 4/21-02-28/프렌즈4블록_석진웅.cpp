#include <bits/stdc++.h>
using namespace std;

bool tmp[30][30];

//정사각형 모양의 블럭이 있는지 체크
bool check(int x, int y, vector<string> board, int n, int m){
    if(x+1 >=n || y+1>=m)return false;
    if(board[y][x]==board[y][x+1] && board[y][x+1]==board[y+1][x] && board[y+1][x]==board[y+1][x+1]) return true;
    return false;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while(true){
        memset(tmp,0,sizeof(tmp));
        //정사각형 블럭 존재 시 tmp 이차원 배열에 체크표시(한꺼번에 처리해주기 위함)
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]!='0' && check(j,i,board,n,m)){
                    tmp[i][j]=true;
                    tmp[i][j+1]=true;
                    tmp[i+1][j]=true;
                    tmp[i+1][j+1]=true;
                }
            }
        }
        //만약 정사각형 블럭이 하나도 존재하지 않으면 플래그 표시
        //존재한다면 값 더해주면서 지워준다.
        bool err=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(tmp[i][j]){
                    err=true;
                    board[i][j]='0';
                    answer+=1;
                }
            }
        }
        if(err==false)break;
        //지워진 블럭을 제외하고 순서대로 큐에 담아주면서 지운 후 아래에서부터 값 순차적으로 넣어주기
        queue<char> q;
        for(int col=0;col<n;col++){
            for(int row=m-1;row>=0;row--){
                if(board[row][col]!='0'){
                    q.push(board[row][col]);
                    board[row][col]='0';
                }
            }
            int row=m-1;
            while(!q.empty()){
                board[row][col]=q.front();
                q.pop();
                row--;
            }
        }
    }
    return answer;
}
