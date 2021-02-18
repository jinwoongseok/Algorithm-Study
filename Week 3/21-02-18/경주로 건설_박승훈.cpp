#include <string>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321



bool check[25][25];
int D[25][25][4];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int Size;
int Min = INF;


void bfs(vector<vector<int>> board) {
    priority_queue<pair<pair<int,int>, pair<int, int>>> q;
    /* 자동차의 모든 방향에서 생각. */
    q.push(make_pair(make_pair(0, 0),make_pair(0,0))); // 비용 방향 x y
    q.push(make_pair(make_pair(0, 1), make_pair(0, 0))); // 비용 방향 x y
    q.push(make_pair(make_pair(0, 2), make_pair(0, 0))); // 비용 방향 x y
    q.push(make_pair(make_pair(0, 3), make_pair(0, 0))); // 비용 방향 x y
    D[0][0][0] = 0;
    D[0][0][1] = 0;
    D[0][0][2] = 0;
    D[0][0][3] = 0;

    while (!q.empty()) {
        int cur_cost = -q.top().first.first; // 현재 비용
        int cur_dir = q.top().first.second; // 현재 방향
        int cx = q.top().second.first;
        int cy = q.top().second.second; // 현재 위치
        q.pop();




        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            int next_dir = 0;
            if (dx[i] == -1 && dy[i] == 0) next_dir = 0; // 북
            else if (dx[i] == 0 && dy[i] == 1) next_dir = 1; // 동
            else if (dx[i] == 1 && dy[i] == 0) next_dir = 2; // 남
            else if (dx[i] == 0 && dy[i] == -1) next_dir = 3; // 서

            if (abs(next_dir - cur_dir) == 2) continue; // 왔던 경로를 다시 오는 경우는 제와
            if (nx >= 0 && ny >= 0 && nx < Size && ny < Size && board[nx][ny] == 0) {


                    if (next_dir == cur_dir) { // 직선 경주로 , 최소 비용 갱신
                        if (D[nx][ny][next_dir] > cur_cost + 100) {
                            D[nx][ny][next_dir] = cur_cost + 100;
                            q.push(make_pair(make_pair(-D[nx][ny][next_dir], next_dir), make_pair(nx, ny)));

                        }
                    }
                    else { // 커브 경주로 , 최소 비용 갱신
                        if (D[nx][ny][next_dir] > cur_cost + 600) {
                            D[nx][ny][next_dir] = cur_cost + 600;
                            q.push(make_pair(make_pair(-D[nx][ny][next_dir], next_dir), make_pair(nx, ny)));
                        }
                    }

            }
        }
    }
    for (int i = 0; i < 4; i++) {
        Min = min(Min, D[Size - 1][Size - 1][i]);
    }
    return;
}
int solution(vector<vector<int>> board) {
    int answer = 0;
    Size = board.size();
    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < Size; i++)
            for (int j = 0; j < Size; j++)
                D[i][j][k] = INF;

    }

    bfs(board);
    answer = Min;
    return answer;
}
