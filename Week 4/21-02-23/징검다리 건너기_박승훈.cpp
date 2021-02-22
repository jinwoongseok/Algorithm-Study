#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// mid 만큼의 인원이 징검다리를 건널 때 0이 되는 돌의 개수 찾기
int check(int mid, vector<int>& stone) {
    int cnt = 0,Max = 0;

    for (int i = 0; i < stone.size(); i++) {
        if (stone[i] - mid <= 0) cnt++; // 0이 되는 돌의 개수 세기
        else {
            Max = max(Max, cnt); // 연속으로 0이 되는 돌 = Max
            cnt = 0;
        }
    }
    Max = max(Max, cnt);
    return Max; 
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int left=1,right= *max_element(stones.begin(), stones.end());


    if (k > 1) {
    // 건널 수 있는 디딤돌의 개수가 1개보다 많다면 이분 탐색

        while (left != right) {
            int mid = (left + right) / 2; // 징검다리를 건넌 인원
            int tmp = check(mid, stones);

            if (tmp >= k) right = mid; // 연속으로 0이 되는 돌의 개수가 k보다 크거나 같을때 => 건넌 인원을 줄인다.
            else left = mid + 1; // 연속으로 0이되는 돌의 개수가 작을 때 => 건넌 인원을 늘린다.
        }
    }
    else left = *min_element(stones.begin(), stones.end()); 
    // 건널 수 있는 디딤돌의 개수가 1개이면 최소값 만큼 친구들이 건널 수 있다.

    answer = left;
    return answer;
}

/*
    슬라이딩 윈도우 응용으로 생각 => 시간초과
    int answer = max_element(stones.begin(), stones.end());

    if (k > 1) {
        for (int i = 0; i < stones.size() - k+1; i++) {
            int Max = *max_element(stones.begin() + i, stones.begin() + i + k); -> 윈도우 크기만큼 체크해서 최대 값 찾기
           answer = min(answer,Max); -> 최대 값중 최소 값 찾기
        }
    }
    else answer = *min_element(stones.begin(), stones.end());
    return answer;

*/

/*
    1. r=5 l=1 , mid = 3 , tmp = 3 
    2. r=3 l=1 , mid = 2 , tmp = 2 
    3. r=3 l=3 , break, answer=left  
*/