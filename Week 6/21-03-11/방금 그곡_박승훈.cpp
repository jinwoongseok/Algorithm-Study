#include <iostream>
#include <string>
#include <vector>
using namespace std;


// 악보 바꾸는 함수
string change(string change_melody)
{
    string tmp = "";

    for (int i = 0; i < change_melody.size(); i++) {
        if (i!=change_melody.size()-1&&change_melody[i + 1] == '#') {
            tmp += c;
            i++;
        }
        else
            tmp += change_melody[i];
    }
    return tmp;
}
string solution(string m, vector<string> musicinfos) {
    string answer = "";
    return answer;

    for (int i = 0; i < musicinfos.size(); i++) {
        int play = stoi(musicinfos[i].substr(6, 2)) * 60 + stoi(musicinfos[i].substr(9, 2)) - stoi(musicinfos[i].substr(0, 2)) * 60 - stoi(musicinfos[i].substr(3, 2));
    }
}
/*
풀이
1. 구조체를 만들어 재생시간(play) (끝난시간-시작시간), title, melody 를 넣는다.
- melody 처리? # 처리.
2. melody.size() < play : 음악 반복 (재생된 시간 만큼 멜로디 이어붙이기 )
3. melody.size() > play : 처음부터 재생시간만큼 멜로디를 잘라준다. (예시 1)
4. melody와 m 비교하여 찾아주기 
*/
int main() {
    return 0;
}

/*
* 조건1. 멜로디 기억
* 조건 2. 네오가 기억하는 멜로디는 음악 끝부분과 처음 부분 일 수도 (한곡재생)
* 조건 3. 네오가 기억한 멜로디가 있다해도 (처음 or 끝) 그 곡이 기억하는 곡이 아닐 수도 ( 중간에서 끊기 )
* 
* 기억한 멜로디를 재생 시간과 제공된 악보를 보면서 비교.
* 음악제목, 재생이 시작되고 끝난시간, 악보 
* C, C#, D, D#, E, F, F#, G, G#, A, A#, B 12개이다.
* 각 음은 1분에 1개씩 재생.
* 음악은 처음부터 재생. 
음악 길이 > 재생된 시간 => 처음부터 재생시간 만큼 재생
음악 길이 < 재생된 시간 =>음악이 반복
*/
