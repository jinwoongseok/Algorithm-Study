#include <bits/stdc++.h>
using namespace std;

string board[16];

void encoding(vector<int> arr, int n){
    for(int i=0;i<arr.size();i++){
        int val=arr[i];
        //16자리의 이진수로 표현해주는 함수
        string enc=bitset<16>(val).to_string();
        //start 인덱스 설정
        int s=16-n;
        for(int j=0;j<n;j++){
            //이미 #표시되어있다면 통과
            if(board[i][j]=='#'){
                s++;
                continue;
            }
            if(enc[s]=='1'){
                board[i][j]='#';
                s++;
            }
            else{
                board[i][j]=' ';
                s++;
            }
        }
    }
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    encoding(arr1, n);
    encoding(arr2, n);
    for(int i=0;i<n;i++){
        string str="";
        for(int j=0;j<n;j++){
            str+=board[i][j];
        }
        answer.push_back(str);
    }
    return answer;
}
