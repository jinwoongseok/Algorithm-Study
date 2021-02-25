#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> save;
int num,idx,tmp_num;

int solution(string dartResult) {
    int answer = 0;
    save.resize(4);
    string tmp = "";

    for (int i = 0; i < dartResult.size(); i++) {
        if (dartResult[i] >= '0' && dartResult[i] <= '9') { // 다트의 점수 
            tmp += dartResult[i];
        }
        else {
            if(!tmp.empty()) tmp_num = stoi(tmp);

            if (dartResult[i] == 'S') {
                save[idx] = pow(tmp_num, 1);
                idx++;
            }
            else if (dartResult[i] == 'D') {
                save[idx] = pow(tmp_num, 2);
                idx++;
            }
            else if (dartResult[i] == 'T') {
                save[idx] = pow(tmp_num, 3);
                idx++;
            } // 보너스 S,D,T 에 맞게 점수 조정
            else if (dartResult[i] == '*') {
                if (idx != 1) for (int j = idx-2; j < idx; j++) save[j] *= 2; // 스타상이 첫번째 기회에 나오지 않았을 때
                else save[idx - 1] *= 2; // 첫번째 기회에 나왔을 때
            } 
            else if (dartResult[i] == '#') {
                save[idx - 1] *= -1; // 아차상
            }
            tmp.clear();
        }
    }
    answer = save[0] + save[1] + save[2];
    return answer;
}
