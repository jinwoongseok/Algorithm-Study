#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<string> makePair(string s) {
    vector<string> ans;

    for (int i = 0; i < s.size() - 1; i++) {
        string tmp = "";
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            tmp += tolower(s[i]);
        }
        else continue;
        if ((s[i + 1] >= 'a' && s[i + 1] <= 'z') || (s[i + 1] >= 'A' && s[i + 1] <= 'Z')) {
            tmp += tolower(s[i + 1]);
        }
        else continue;

        if(tmp.size()>1) ans.push_back(tmp);
    }
    return ans;
}

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> s1;
    vector<string> s2;
    vector<bool> check;

    //1. �� ���� �빮��, �ҹ��ڷ� ����鼭 �ν����� ����� (����,Ư�����ڰ� ���Ե� ��� ������.)
    s1 = makePair(str1); sort(s1.begin(), s1.end());
    s2 = makePair(str2); sort(s2.begin(), s2.end());

    //2. �� ���͸� ���Ͽ� ��ī�� 
    if (s1.size() == 0 && s2.size() == 0) answer = 65536;
    else {
        double inter = 0; // ������
        double uni = double(s1.size()+s2.size()); // ������
        check.assign(s2.size(), false);

        for (int i = 0; i < s1.size(); i++) {
            for (int j = 0; j < s2.size(); j++) {
                if (check[j] == false && s1[i] == s2[j]) {
                    check[j] = true;
                    inter++;
                    break;
                }
            }
        }
        uni -= inter;
        inter = inter / uni;
        answer = floor(inter * 65536);
    }

    return answer;
}