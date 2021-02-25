#include <bits/stdc++.h>
using namespace std;
stack<int> stk;
vector<string> v;
int solution(string dartResult) {
    int answer = 0;
    string buf="";
    //전처리 과정, 벡터에 세 개의 연산을 나눠 담아줌
    for(int i=0;i<dartResult.size();i++){
        if(dartResult[i]>='0' && dartResult[i]<='9'){
            if(i!=0 && dartResult[i-1]=='1'){
                buf+=dartResult[i];
                continue;
            }
            if(buf.size()!=0) v.push_back(buf);
            buf.clear();
            buf+=dartResult[i];
        }
        else buf+=dartResult[i];
    }
    if(buf.size()!=0) v.push_back(buf);
    
    //처리 시작
    for(int i=0;i<v.size();i++){
        string tmp;
        int num=0;
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]>='0' && v[i][j]<='9'){
                tmp+=v[i][j];
                continue;
            }
            if(v[i][j]=='D'){
                num=stoi(tmp);
                num=(int)pow(num,2);
                stk.push(num);
                tmp.clear();
            }
            else if(v[i][j]=='T'){
                num=stoi(tmp);
                num=(int)pow(num,3);
                stk.push(num);
                tmp.clear();
            }
            else if(v[i][j]=='S'){
                num=stoi(tmp);
                stk.push(num);
                tmp.clear();
            }
            else if(v[i][j]=='*'){
                int a=stk.top();
                stk.pop();
                if(stk.empty()){
                    a*=2;
                    stk.push(a);
                }
                else{
                    int b=stk.top();
                    stk.pop();
                    a*=2;
                    b*=2;
                    stk.push(b);
                    stk.push(a);
                }
            }
            else if(v[i][j]=='#'){
                int a=stk.top();
                stk.pop();
                a=-a;
                stk.push(a);
            }
        }
    }
    //스택 내부 값들을 전부 꺼내 더해준다.
    while(!stk.empty()){
        answer+=stk.top();
        stk.pop();
    }
    return answer;
}

//--------------------------------------------- 다른 사람 풀이

int solution(string dartResult) {
    stringstream ss(dartResult);

    int sum[3] = { 0, 0, 0 };
    int options[3] = { 1, 1, 1 };
    for (int i = 0; i < 3; i++) {
        int score;
        char bonus;
        char option;
        //공백문자와 개행문자 구분짓고, 더 이상 score 자료형에 맞는 정보가 없을때까지 스트림에서 num으로 데이터를 추출/복사
        ss >> score;
        //char get
        bonus = ss.get();
        option = ss.get();
        //char unget
        if (option != '*' && option != '#') {
            ss.unget();
        }

        switch (bonus) {
        case 'S':
            sum[i] += pow(score, 1);
            break;
        case 'D':
            sum[i] += pow(score, 2);
            break;
        case 'T':
            sum[i] += pow(score, 3);
            break;
        default:
            break;
        }

        switch (option) {
        case '*':
            if (i > 0 && options[i - 1]) options[i - 1] *= 2;
            options[i] *= 2;
            break;
        case '#':
            options[i] = -options[i];
            break;
        default:
            break;
        }
    }

    return sum[0] * options[0] + sum[1] * options[1] + sum[2] * options[2];
}
