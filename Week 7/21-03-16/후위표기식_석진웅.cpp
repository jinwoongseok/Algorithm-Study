#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    stack<char> s;
    cin >> str;
    for(int i=0;i<str.size();i++){
        if(str[i]=='('){
            s.push(str[i]);
        }
        else if(str[i]==')'){
            while(s.top()!='('){
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
        else if(str[i]>='A' && str[i]<='Z'){
            cout << str[i];
        }
        else if(str[i]=='*' || str[i]=='/'){
            while(!s.empty() && (s.top()=='*' || s.top()=='/')){
                cout << s.top();
                s.pop();
            }
            s.push(str[i]);
        }
        else if(str[i]=='+' || str[i]=='-'){
            while(!s.empty() && s.top()!='('){
                cout << s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    return 0;
}
