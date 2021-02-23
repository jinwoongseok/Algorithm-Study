#include <bits/stdc++.h>
using namespace std;
stack<int> stk;
int n;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    n=board.size();
    for(int i=0;i<moves.size();i++){
        int col=moves[i]-1;
        for(int j=0;j<n;j++){
            if(board[j][col]!=0){
                if(!stk.empty() && stk.top()==board[j][col]){
                    stk.pop();
                    answer+=2;
                }
                else stk.push(board[j][col]);
                board[j][col]=0;
                break;
            }
        }
    }
    return answer;
}
