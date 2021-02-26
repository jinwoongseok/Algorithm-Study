#include <string>
#include <vector>
using namespace std;

vector<vector<char>> board_;
vector<vector<bool>> check;

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    // 보드 char로 초기화
    board_.resize(m,vector<char> (n));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            board_[i][j] = board[i][j];
    
    while (true) {
        bool flag = false;
        check.assign(m, vector<bool>(n, false));

        // 탐색
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                char tmp = board_[i][j];
                if (tmp == '-') continue;
                // 2*2만큼 같을 때
                if (tmp == board_[i][j + 1] && tmp == board_[i + 1][j] && tmp == board_[i + 1][j + 1]) {

                    // 지워져야 되지만 체크가 안된 블록일 경우 answer++
                    if (check[i][j] == false) answer++;
                    if (check[i][j+1] == false) answer++;
                    if (check[i+1][j] == false) answer++;
                    if (check[i+1][j+1] == false) answer++;

                    // 지워지는 블록 체크
                    check[i][j] = check[i + 1][j] = check[i][j + 1] = check[i + 1][j + 1] = true;
                    flag = true;
                }
            }
        }
        // 지워지는 블록이 없을경우 종료
        if (!flag) break;

        // 지우기
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (check[i][j] == true) board_[i][j] = '-';
            }
        }

        // 이동
        for (int i = 0; i < n; i++) {
            for (int j = m-1; j >= 0 ; j--) {
                char tmp = board_[j][i];
                if (j == m - 1 ||tmp == '-') continue;

                for (int k = j; k < m - 1; k++) {
                   if (board_[k + 1][i] == '-') {
                       board_[k][i] = board_[k + 1][i]; // '-' 올리기
                       board_[k + 1][i] = tmp; // 내리기
                   }
                }
                
            }
        }
    }
    return answer;
}