#include <bits/stdc++.h>
#define int long long
using namespace std;

int calc(int a, int b, string op){
    if(op=="+")return a+b;
    else if(op=="-")return a-b;
    else return a*b;
}

long long solution(string expression) {
    long long answer = 0;
    string buf="";
    vector<string> v;
    for(int i=0;i<expression.size();i++){
        //연산기호일 경우
        if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*'){
            //buf 값 벡터에 저장
            v.push_back(buf);
            string op="";
            op+=expression[i];
            //연산기호 벡터에 저장
            v.push_back(op);
            //buf 클리어
            buf.clear();
        }
        //연산기호 아닐경우 버프에 스트링값 계속해서 저장
        else{
            buf+=expression[i];
        }
        //인덱스가 끝이고 버프가 비어있지 않다면 벡터에 버프값 저장
        if(i==expression.size()-1 && buf.size()!=0){
            v.push_back(buf);
        }
    }
    vector<int> oper;
    oper.push_back(1);
    oper.push_back(2);
    oper.push_back(3);
    //각 조합의 경우에 대해 연산
    do{
        vector<string> tmp;
        tmp.assign(v.begin(), v.end());
        for(int i=0;i<oper.size();i++){
            string op;
            //1:+, 2:-, 3:*
            if(oper[i]==1)op="+";
            else if(oper[i]==2)op="-";
            else op="*";
            for(int j=1;j<tmp.size();j++){
                //tmp[j]가 연산기호일 경우 연산 진행 후 tmp에서 j,j+1번째 지우기
                if(tmp[j]==op){
                    int res=calc(stoll(tmp[j-1]),stoll(tmp[j+1]),tmp[j]);
                    tmp[j-1]=to_string(res);
                    tmp.erase(tmp.begin()+j);
                    tmp.erase(tmp.begin()+j);
                    j--;
                }
            }
        }
        answer=max(answer,abs(stoll(tmp[0])));
    }while(next_permutation(oper.begin(), oper.end()));
    return answer;
}
