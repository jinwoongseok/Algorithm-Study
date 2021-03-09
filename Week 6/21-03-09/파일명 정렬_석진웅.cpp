#include <bits/stdc++.h>
using namespace std;

struct info{
    string head;
    int number;
    string tail="";
    string originHead;
    string originNum;
    int idx;
};

//c++ 정렬은 불안정 정렬이기 때문에 동일한 값일때의 정렬 후 인덱스 순서가 오름차순이 아닐 수 있음
bool comp(info a, info b){
    if(a.head==b.head){
        if(a.number==b.number){
            return a.idx<b.idx;
        }
        return a.number<b.number;
    }
    return a.head<b.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<info> list;
    for(int i=0;i<files.size();i++){
        string buf;
        string obuf;
        int idx=0;
        while(files[i][idx]<'0' || files[i][idx]>'9'){
            //원래의 문자 저장
            obuf+=files[i][idx];
            //변환 문자 저장
            buf+=tolower(files[i][idx]);
            idx++;
        }
        string oh=obuf;
        string h=buf;
        buf.clear();
        int cnt=0;
        while(cnt<5 && files[i][idx]>='0' && files[i][idx]<='9'){
            buf+=files[i][idx];
            idx++;
            cnt++;
        }
        //원문자 저장
        string on=buf;
        //숫자 변환해 저장
        int n=stoi(buf);
        buf.clear();
        //tail 저장
        string t=files[i].substr(idx);
        list.push_back({h,n,t,oh,on,i});
    }
    sort(list.begin(),list.end(),comp);
    for(int i=0;i<list.size();i++){
        string str;
        str+=list[i].originHead;
        str+=list[i].originNum;
        str+=list[i].tail;
        answer.push_back(str);
    }
    return answer;
}
