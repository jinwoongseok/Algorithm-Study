#include <string>
#include <vector>
#include <algorithm>
using namespace std;


typedef struct {
    string HEAD; // ���ڿ�
    int NUMBER; // ����
    int TAIL; // ���� ����

}file;

bool cmp(file a, file b) {
    if (a.HEAD == b.HEAD) {
        if (a.NUMBER == b.NUMBER) return a.TAIL < b.TAIL; // 3. tail ���� ���� ����
        return a.NUMBER < b.NUMBER; // 2. number ��������
    }
    return a.HEAD < b.HEAD; // 1. head ���ĺ� ����
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<file> f1;

    // head, number ,tail �����
    for (int i = 0; i < files.size(); i++) {
        bool flag = false; string head = ""; string num = "";
        file tmp;

        for (int j = 0; j < files[i].size(); j++) {
            if (files[i][j] >= '0' && files[i][j] <= '9') { // 2. Number �����
                num += files[i][j];
                flag = true;
            }
            else {
                if (flag == true) break; // 3. Tail�� break;
                else {  // 1. Head �����
                    if (files[i][j] >= 'a' && files[i][j] <= 'z' || files[i][j] >= 'A' && files[i][j] <= 'Z') head += tolower(files[i][j]);
                    else head += files[i][j];
                }
            }
        }

        tmp.HEAD = head; tmp.NUMBER = stoi(num); tmp.TAIL = i;
        f1.push_back(tmp);
    }
    
    sort(f1.begin(), f1.end(), cmp);

    for (int i = 0; i < f1.size(); i++) {
        int idx = f1[i].TAIL;
        answer.push_back(files[idx]);
    }
    return answer;
}