#include <bits/stdc++.h>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    map<string,int> v1;
    map<string,int> v2;
    string buf;
    for(int i=0;i<str1.size();i++){
        //소문자로 통일
        str1[i]=tolower(str1[i]);
        buf+=str1[i];
        //소문자 이외의 문자열이 나올 시 넘김
        if(str1[i]<'a'||str1[i]>'z'){
            buf.clear();
            continue;
        }
        //맵에 갯수 추가 후 buf의 앞글자 삭제
        if(buf.size()==2){
            v1[buf]++;
            buf.erase(0,1);
        }
    }
    buf.clear();
    for(int i=0;i<str2.size();i++){
        str2[i]=tolower(str2[i]);
        buf+=str2[i];
        if(str2[i]<'a'||str2[i]>'z'){
            buf.clear();
            continue;
        }
        if(buf.size()==2){
            v2[buf]++;
            buf.erase(0,1);
        }
    }
    //중복 갯수
    int overlap=0;
    map<string, int> res;
    //우선 res에 v1의 자료들 전부 담아주기
    for(auto& i:v1){
        res[i.first]=i.second;
    }
    //이후 중복을 체크해가면서 res에 추가하기
    for(auto& i:v2){
        if(res.find(i.first)==res.end()){
            res[i.first]=i.second;
        }
        else{
            overlap+=min(res[i.first],i.second);
            res[i.first]=max(res[i.first],i.second);
        }
    }
    //합집합 크기 구하기
    int total=0;
    for(auto& i:res){
        total+=i.second;
    }
    //모두 공집합일 경우
    if(total==0 && overlap==0){
        answer=65536;
    }
    //아닐 시 계산
    else{
        double tmp=(double)(overlap)/(double)(total);
        tmp*=65536;
        answer=(int)(floor(tmp));
    }
    return answer;
}
