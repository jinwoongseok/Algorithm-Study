#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> m;

bool cmp(string a, string b) {
    return a.size() < b.size();
}
vector<int> solution(string s) {
    vector<int> answer;
    vector<string> tmp;
    string tuple;

    for (int i = 1; i < s.size() - 1; i++) {
        // {}를 제외한 숫자와 ,의 문자열을 만든다.
        if (s[i] == '{') {
            tuple = "";
            for (int j = i + 1; j < s.size() - 1; j++) {
                if (s[j] == '}') {
                    i = j;
                    break;
                }
                tuple += s[j];
            }
            tmp.push_back(tuple);
        }
    }
    // 문자열 길이의 오름차순으로 정렬
    sort(tmp.begin(), tmp.end(), cmp);

    int size = 0;

    while (size!=tmp.size()) {
        tuple = tmp[size];
        string num;
        // 원소를 이용해 튜플 구하기
        for (int i = 0; i < tuple.size(); i++) {
            if (tuple[i] >= '0' && tuple[i] <= '9') {
                num += tuple[i];
            }
            if (tuple[i] == ',' || i == tuple.size() - 1) {
                if (m[num] == 0) {
                    answer.push_back(stoi(num));
                    m[num]++;
                }
                num.clear();
            }
        }
        size++;
    }
    return answer;
}
