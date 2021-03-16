#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> m;

vector<int> solution(string msg) {
    vector<int> answer;
    string word = "";
  
    // 1. 사전 초기화
    for (char i = 'A'; i <= 'Z'; i++) {
        word += i;
        m[word] = i - 'A' + 1;
        word.clear();
    }
    
    // 2. 사전에 등록할 다음 번호
    int idx = 27;
    string tmp = "";
    for (int i = 0; i < msg.size(); i++) {
        tmp += msg[i];

        if (m.find(tmp) == m.end()) { // 해당 문자열이 사전에 없을 때
            m[tmp] = idx++; // 사전에 등록
            tmp.pop_back(); 
            answer.push_back(m[tmp]);
            tmp.clear(); // 이전 문자열 idx값 저장
            i--; // i++떄문에 해당 위치로 복귀하기 위해
        }
    }

    if (tmp.size() > 0) answer.push_back(m[tmp]); // 처리하지 못한 문자열의 사전 값 입력
    return answer;
}
