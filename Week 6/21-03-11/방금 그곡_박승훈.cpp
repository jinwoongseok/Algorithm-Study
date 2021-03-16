#include <string>
#include <vector>
#include <sstream>
using namespace std;


// 악보 바꾸는 함수 , #이 붙은 음계는 소문자로 변환.
string change(string change_melody) {
    string tmp = "";

    for (int i = 0; i < change_melody.size(); i++) {
        if (i!=change_melody.size()-1 && change_melody[i + 1] == '#') {
            if(change_melody[i]=='C') tmp += 'c';
            else if(change_melody[i]=='D') tmp += 'd';
            else if(change_melody[i]=='F') tmp += 'f';
            else if(change_melody[i]=='G') tmp += 'g';
            else if(change_melody[i]=='A') tmp += 'a';
                
            i++;
        }
        else
            tmp += change_melody[i];
    }
    return tmp;
}
string solution(string m, vector<string> musicinfos) {
    string answer = "";

    m=change(m); // 멜로디 변환
    int ans_time=0; // 재생된 최대 시간 측정
    for (int i = 0; i < musicinfos.size(); i++) {
        istringstream ss(musicinfos[i]); 
        string buffer;
        int idx=0; int time=0; 
        int sh=0; int sm=0;
        int eh=0; int em=0;
        int line=0;
        string title;
        string song;
        
        while (getline(ss, buffer, ',')) { // 문자열 parsing (sstream을 이용) 
            if(idx==0){
                sh=stoi(buffer.substr(0,2))*60;
                sm=stoi(buffer.substr(3,2));
            }
            else if(idx==1){
                eh=stoi(buffer.substr(0,2))*60;
                em=stoi(buffer.substr(3,2));
            }
            else if(idx==2){
                title=buffer;
            }
            else if(idx==3){
                song=change(buffer);
            }
            idx++;
        }
        time = (em+eh)-(sm+sh); // time : 재생시간, title : 곡 제목, song : 악보
        
        if(song.size() < time) { // 조건1. 악보의 길이가 재생된 시간보다 작을 때 (악보 늘림)
            string tmp = song;
        
            for(int j = 1; j < time / tmp.size(); j++)
                song += tmp;
            for(int j = 0; j < time % tmp.size(); j++)
                song += tmp[j];
        }
        else  // 조건2. 악보의 길이가 재생된 시간보다 크거나 같을 때 (악보 자르기)
            song = song.substr(0, time);
        
         if(song.find(m) != string::npos) { // find함수를 이용해 멜로디가 악보에 포함 되는지 확인.
            if(ans_time < time) { // 포함되고, 최대 재생시간보다 큰 재생시간을 가질 때 
                answer = title;
                ans_time = time;
            }
         }
    }
    if (answer == "") answer = "(None)";
    return answer;
}
