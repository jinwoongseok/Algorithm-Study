#include <string>
#include <vector>
using namespace std;

// 10진법 숫자를 base 진법으로 바꾸는 함수
string change(int n,int base) {
    vector<int> v;
    string tmp = "";

    while (true) {
        v.push_back(n % base);   
        n /= base;
        if (n == 0) break;
    }

    vector<int>::reverse_iterator rit; // reverse_iterator로 vector의 뒤에서 부터 값을 읽어온다.
    for (rit = v.rbegin(); rit != v.rend(); rit++) {
        if (*rit >= 10) {
            tmp+= (*rit - 10 + 'A'); // 10이상일 때
        }
        else {
            tmp+=(*rit+'0'); // 10미만일 때
        }
    }
    return tmp;
}

string solution(int n, int t, int m, int p) {
    string tube = "";
    int num = 0; int idx = 1;

    while (true) {
        string change_num = change(num,n);

        for (int i = 0; i < change_num.length(); i++) {
            if (idx == p) tube += change_num[i]; // 튜브의 순서일 때
            idx++; // 순서를 증가시킨다.
            if (idx > m) idx = 1; // 순서 원위치
            if (tube.size() == t) {
                return tube;
            } // 미리 구할 숫자만큼 구했을 때
        }
        num++;  // 숫자 증가
    }
}
