#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    
    for (int i = 0; i < n; i++) {
        string tmp1 = ""; int tmp_num1 = arr1[i];
        string tmp2 = ""; int tmp_num2 = arr2[i];
        string ans = "";

        for (int j = 0; j < n; j++) {
            if (tmp_num1 % 2 != 0) tmp1 += '#';
            else tmp1 += ' ';
            
            if (tmp_num2 % 2 != 0) tmp2 += '#';
            else tmp2 += ' ';
            tmp_num1 /= 2; tmp_num2 /= 2;
        } // 지도 1과 2 만들기
        

        for (int j = n-1; j >=0; j--) {
            if (tmp1[j] == '#' || tmp2[j] == '#') {
                ans += '#';
            }
            else {
                ans += ' ';
            }
        }// 지도 1과 2의 정보를 토대로 ans 지도 만들기
        answer.push_back(ans);
    }

    return answer;
}
int main() {
    vector<int> a = { 9, 20, 28, 18, 11 };
    vector<int> b = { 30, 1, 21, 17, 28 };

    solution(5, a, b);
}

