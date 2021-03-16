#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define MAX 500001
typedef pair<int,int> pii;
int arr[MAX];
int n;
stack<pii> s;

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    for(int i=1;i<=n;i++){
        int h=arr[i];
        while(!s.empty()){
            if(s.top().first>h){
                cout << s.top().second << " ";
                s.push({h,i});
                break;
            }
            else s.pop();
        }
        if(s.empty())cout << 0 << " ";
        s.push({h,i});
    }
    return 0;
}
