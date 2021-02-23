#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    //최소 1명에서 최대 2억명까지 이동가능
    int s=1;
    int e=200'000'000;
    //이분 탐색
    while(s<=e){
        int mid=(s+e)/2;
        vector<int> arr;
        arr.assign(stones.begin(), stones.end());
        for(int i=0;i<arr.size();i++){
            if(arr[i]-mid<0){
                arr[i]=0;
            }
            else arr[i]-=mid;
        }
        int cnt=0;
        bool err=false;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0)cnt++;
            else cnt=0;
            //만약 연속으로 0인 다리가 k개 존재하면 플래그 표시 후 탈출
            if(cnt==k){
                err=true;
                break;
            }
        }
        if(err==false){
            s=mid+1;
        }
        else{
            e=mid-1;
            answer=mid;
        }
    }
    return answer;
}
