#include <bits/stdc++.h>
using namespace std;

char number[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
//n진수로 변환하는 함수
string convert(int num, int n){
    string str="";
    if(num==0){
        return "0";
    }
    while(num!=0){
        int a=num/n;
        int b=num%n;
        str=number[b]+str;
        num=a;
    }
    return str;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int cnt=0;
    int num=0;
    int tube=0;
    //구해야 하는 수까지 루프
    while(tube<t){
        string tmp=convert(num,n);
        for(int i=0;i<tmp.size();i++){
            //튜브의 순서
            if((cnt%m)==p-1){
                answer+=tmp[i];
                tube++;
            }
            if(tube>=t)break;
            //게임 진행 카운트 증가
            cnt++;
        }
        //숫자 증가
        num++;
    }
    return answer;
}
