#include <string>
#include <vector>
#include <algorithm>
using namespace std;


typedef struct {
    string HEAD; // 문자열
    int NUMBER; // 숫자
    int TAIL; // 들어온 순서

}file;

bool cmp(file a, file b) {
    if (a.HEAD == b.HEAD) {
        if (a.NUMBER == b.NUMBER) return a.TAIL < b.TAIL; // 3. tail 먼저 들어온 순서
        return a.NUMBER < b.NUMBER; // 2. number 오름차순
    }
    return a.HEAD < b.HEAD; // 1. head 알파벳 순서
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<file> f1;

    // head, number ,tail 만들기
    for (int i = 0; i < files.size(); i++) {
        bool flag = false; string head = ""; string num = "";
        file tmp;

        for (int j = 0; j < files[i].size(); j++) {
            if (files[i][j] >= '0' && files[i][j] <= '9') { // 2. Number 만들기
                num += files[i][j];
                flag = true;
            }
            else {
                if (flag == true) break; // 3. Tail은 break;
                else {  // 1. Head 만들기
                    if (files[i][j] >= 'a' && files[i][j] <= 'z' || files[i][j] >= 'A' && files[i][j] <= 'Z') head += tolower(files[i][j]);
                    else head += files[i][j];
                }
            }
        }

        tmp.HEAD = head; tmp.NUMBER = stoi(num); tmp.TAIL = i;
        f1.push_back(tmp);
    }
    
    sort(f1.begin(), f1.end(), cmp);

    for (int i = 0; i < f1.size(); i++) {
        int idx = f1[i].TAIL;
        answer.push_back(files[idx]);
    }
    return answer;
}