#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

typedef struct {
    string hour;
    string min;
    string sec;
    string msec;
    string check;
}Time;

bool cmp(pair<int,int> a, pair<int, int> b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

vector<pair<int,int>> Res;

int solution(vector<string> lines) {
    int answer = 0;
    Time t1;

    /* 시간을 구분*/
    for (int i = 0; i < lines.size(); i++) {

        istringstream ss(lines[i]); // 문자열 포맷 parsing 할때 사용.
        string buffer;
        int idx=0;

        while (getline(ss, buffer, ' ')) { // ' ' 기준으로 문자열 parsing
            if (idx == 1) {
                istringstream ss_(buffer);
                string buffer_;
                int idx_ = 0;

                while (getline(ss_, buffer_, ':')) { // ':' 기준으로 문자열 parsing (시간)
                    if (idx_ == 0) t1.hour = buffer_; // h
                    else if (idx_ == 1) t1.min = buffer_; // m
                    else if (idx_ == 2) { 
                        t1.sec = buffer_.substr(0,2);  // s
                        t1.msec = buffer_.substr(3, buffer_.size() - 2); // ms
                    }
                    idx_++;
                }
            }
            else if (idx == 2) {
                buffer.pop_back();
                t1.check = buffer;
            } // 처리 시간
            idx++;
        }


        int end = (stoi(t1.hour) * 3600 + stoi(t1.min) * 60 + stoi(t1.sec)) * 1000 + stoi(t1.msec);
        int start = end +1 - int(stof(t1.check)*1000);
        
        Res.push_back(make_pair(start,0));
        Res.push_back(make_pair(end + 999,1)); // 999 더해준 이유는 끝나는 지점과 다른 시작 지점이 1초 이내에 있을 때를 고려하기 위해서.
    }
    sort(Res.begin(), Res.end(), cmp); // 작업의 시작과 끝 시간만 살펴보기 위해 정렬.

    int Max = 0, cnt = 0;

    for (int i = 0; i < Res.size(); i++) {
        if (Res[i].second == 0) { // 작업이 시작 될때
            cnt++;
        }
        else { // 작업이 끝날 때
            cnt--;
        }
        Max = max(Max, cnt);
    }
    answer = Max;
    return answer;
}