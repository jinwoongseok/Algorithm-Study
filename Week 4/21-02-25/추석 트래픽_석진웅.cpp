#include <bits/stdc++.h>
using namespace std;
#define MAX 86400000

set<int> res;
map<int, vector<int>> m;

int solution(vector<string> lines) {
    int answer = 0;
    //문자열 전처리 후 ms단위로 변환
    for(int i=0;i<lines.size();i++){
        istringstream ss(lines[i]);
        string buf;
        vector<string> v;
        while(getline(ss,buf,' ')){
            v.push_back(buf);
        }
        istringstream iss(v[1]);
        vector<string> date;
        while(getline(iss,buf,':')){
            date.push_back(buf);
        }
        //끝나는 시각
        int e=0;
        e+=stoi(date[0])*3600000;
        e+=stoi(date[1])*60000;
        e+=(int)(stod(date[2])*1000);
        string str;
        for(int j=0;j<v[2].size();j++){
            if(v[2][j]=='s')break;
            str+=v[2][j];
        }
        int dif=(int)(stod(str)*1000);
        //시작 시각
        int s=e-dif+1;
        //전날에 시작했다면 시작지점0
        if(s<0){
            s=0;
        }
        //맵에 표시하기 시작시각은 양수, 끝난시각은 음수
        m[e].push_back(-(i+1));
        m[s].push_back(i+1);
    }
    int l=0;
    int r=0;
    //시작부터 23:59:59.999까지
    while(r<MAX){
        //만약 현재 r 시각에 표시가있고, 그것이 양수라면 업데이트
        if(m.count(r)==1){
            for(auto i:m[r]){
                if(i>0) res.insert(i);
            }
        }
        //l과 r의 길이가 1s일때 갱신
        if(r-l+1==1000){
            answer=max(answer, (int)(res.size()));
            //현재 l 시각에 표시가있고, 그것이 음수라면 업데이트
            if(m.count(l)==1){
                for(auto i:m[l]){
                    if(i<0) res.erase(-i);
                }
            }
            l++;
        }
        r++;
    }
    return answer;
}
