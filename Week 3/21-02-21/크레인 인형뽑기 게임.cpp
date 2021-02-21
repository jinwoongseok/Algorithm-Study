
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> save;

    /* 스택을 이용한 풀이 */
    for (int i = 0; i < moves.size(); i++) {
        int move = moves[i]-1; // 크레인을 이동한 위치

        for (int j = 0; j <board.size() ; j++) {
            int doll = board[j][move]; // 이동한 위치에서 인형찾기

            if (doll != 0) { // 인형을 발견했을 때
                if (!save.empty()) {
                    if (save.top() == doll) { // 바구니의 가장 위의 인형과 같을때
                        save.pop();
                        answer+=2;
                    }
                    else { // 다를 때
                        save.push(doll);
                    }
                }
                else { // 바구니에 인형이 없을 때
                    save.push(doll);
                }
                board[j][move] = 0; // 인형을 꺼낸 동작
                break;
            }
        }

    }

    return answer;
}
