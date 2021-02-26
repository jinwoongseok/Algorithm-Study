#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    // 크루원 도착시간을 오름차순으로 정렬.
    sort(timetable.begin(), timetable.end());

        queue<int> bus;
    map<int, vector<int>> line;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        int busTime = 540 + i * t;
        bus.push(busTime); // 버스 시간


        for (int j = idx; j < timetable.size(); j++) {
            int Hour = stoi(timetable[j].substr(0, 2));
            int Min = stoi(timetable[j].substr(3, 2));
            int Time = Hour * 60 + Min; // 크루원 도착 시간

            if (line[busTime].size() < m && Time <= busTime) line[busTime].push_back(Time); // 버스 시간과 크루원 도착시간에 맞게 줄 세우기
            else { 
                idx = j;
                break; 
            }

        }
    }

    /* 콘의 도착 시간 정하기 */
    int ans = 0;
    while (!bus.empty()) {
        int bus_ = bus.front();
        bus.pop();

        /* 줄 세운 인원(line[bus_].size())이 셔틀 버스의 정원 보다 적을 경우 콘은 버스 시간에 도착
        *  줄 세운 인원(line[bus_].size())이 셔틀 버스의 정원 보다 많거나 같을 경우 콘은 줄 맨 마지막 사람 시간 -1 
        */ 
        if (line[bus_].size() < m) ans = bus_; 
        else ans = line[bus_][line[bus_].size() - 1]-1;
    }

    string H, M;
    if (ans / 60 > 9) H = to_string(ans / 60);
    else H = '0' + to_string(ans / 60);

    if (ans % 60 > 9) M = to_string(ans % 60);
    else M = '0' + to_string(ans % 60);

    answer = H + ':' + M;
    return answer;
}