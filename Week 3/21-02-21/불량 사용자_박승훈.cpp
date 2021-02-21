/* 테스트케이스 1번 .
    처음엔 m에다 check_overlap을 넣었었는데,
    check_overlap 그렇게 되면 제재아이디 == check_overlap인 경우가 발생하므로
    set을 만들어 따로 저장 or map을 하나 더 사용하여 해결
*/
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<string>> save;
vector<string> check;
map<string, int> m;
map<string, int> overlap;
int Size, answer;

// 조합 찾기 백트래킹
void ans(int cnt) {

    if (cnt == Size) {
        string check_overlap = "";
        vector<string> check_copy=check;
        sort(check_copy.begin(), check_copy.end());
        /* 정렬(순서만 다른 중복을 없애기 위해)을 해줘야 하기 떄문에 check_copy 생성
            생성하지 않으면 백트래킹의 특성상 다음 차례때 정렬된 check로 계산하기 떄문에.
        */

        for (int i = 0; i < cnt; i++) {
            check_overlap += check_copy[i];
        }

        if (overlap[check_overlap] == 0) {
            answer++;
            overlap[check_overlap]++;
        }
        return;
    }

    for (int i = 0; i < save[cnt].size(); i++) {
        string tmp = save[cnt][i];
        if (m[tmp] == 0) {
            m[tmp]++;
            check.push_back(tmp);

            ans(cnt + 1);

            check.pop_back();
            m[tmp]--;
        }
    }
    return;
}

int solution(vector<string> user_id, vector<string> banned_id) {

    Size = banned_id.size();
    save.resize(9);

    for (int i = 0; i < Size; i++) {
        string ID = banned_id[i]; // 제재 아이디

        for (int j = 0; j < user_id.size(); j++) {
            bool check = false;
            if (ID.size() == user_id[j].size()) { // 조건 1. 제재 아이디랑 길이가 같아야 한다.
                for (int k = 0; k < ID.size(); k++) {
                    if (ID[k] == '*') continue;
                    else if (user_id[j][k] != ID[k]) { // 조건 2.  제재 아이디의 *를 제외하고 같아야한다.
                        check = true;
                        break;
                    }
                }
                if (!check) save[i].push_back(user_id[j]);
            }
        }
    }

    ans(0);
    return answer;
}
