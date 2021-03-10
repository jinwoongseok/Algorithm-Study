#include <bits/stdc++.h>
using namespace std;

//#을 고려한 음들을 파싱해 담아주는 벡터
vector<string> mv;
struct info{
    int time;
    int idx;
    string name;
};

//기억한 멜로디와 일치하는 곡들을 담는 벡터
vector<info> candidate;

bool comp(info a, info b){
    if(a.time==b.time)return a.idx<b.idx;
    return a.time>b.time;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    //m 문자열 #경우 고려해서 벡터에 담기
    for(int i=0;i<m.size();i++){
        if(i!=(m.size()-1) && m[i+1]=='#'){
            string str="";
            str+=m[i];
            str+=m[i+1];
            mv.push_back(str);
            i++;
        }
        else{
            string str="";
            str+=m[i];
            mv.push_back(str);
        }
    }
    for(int i=0;i<musicinfos.size();i++){
        istringstream ss(musicinfos[i]);
        string buf;
        vector<string> v;
        while(getline(ss,buf,',')){
            v.push_back(buf);
        }
        //시작 시간, 끝 시간 분으로 단위 통일
        int s=0;
        int e=0;
        string hour=v[0].substr(0,2);
        string minute=v[0].substr(3,2);
        s+=stoi(hour)*60;
        s+=stoi(minute);
        hour.clear();
        minute.clear();
        hour=v[1].substr(0,2);
        minute=v[1].substr(3,2);
        e+=stoi(hour)*60;
        e+=stoi(minute);
        
        //악보정보 #고려해서 벡터에 담기
        vector<string> tmp;
        for(int j=0;j<v[3].size();j++){
            if(j!=(v[3].size()-1) && v[3][j+1]=='#'){
                string str="";
                str+=v[3][j];
                str+=v[3][j+1];
                tmp.push_back(str);
                j++;
            }
            else{
                string str="";
                str+=v[3][j];
                tmp.push_back(str);
            }
        }
        
        //재생시간만큼의 악보 벡터에 담기
        int dif=e-s;
        int cnt=0;
        int idx=0;
        vector<string> total;
        while(cnt<dif){
            if(idx==tmp.size()){
                idx=0;
            }
            total.push_back(tmp[idx]);
            cnt++;
            idx++;
        }
        //투포인터 사용
        int mp=0;
        int tp=0;
        while(mp<mv.size()){
            if(tp==total.size())break;
            if(mv[mp]==total[tp]){
                mp++;
                tp++;
                continue;
            }
            else if(mp!=0 && mv[mp]!=total[tp]){
                mp=0;
            }
            else{
                tp++;
            }
        }
        //만약 일치하는게 있다면 후보 벡터에 담기
        if(mp==mv.size()){
            candidate.push_back({dif,i,v[2]});
        }
    }
    if(candidate.size()==0){
        answer="(None)";
    }
    else{
        sort(candidate.begin(),candidate.end(),comp);
        answer=candidate[0].name;
    }
    
    return answer;
}
