#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
    double ratio;
    int idx;
}stage;

vector<int> Clear;
vector<stage> v;

bool cmp(stage a, stage b) {
    if (a.ratio == b.ratio) return a.idx < b.idx;
    return a.ratio > b.ratio;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    Clear.assign(N + 1, 0);

    // 클리어한 인원 체크
    for (int i = 0; i < stages.size(); i++) {
        for (int j = 1; j < stages[i]; j++) {
            Clear[j]++;
        }
    }

    // 도달한 전체 인원수 - 클리어 인원 =  클리어 못한 인원
    int size = stages.size();

    for (int i = 1; i <= N; i++) {
        if (size != 0) {
            double R = (double)(size - Clear[i]) / (double)size;
            v.push_back({ R,i });
            size = Clear[i];
        }
        else {
            v.push_back({ 0,i });
        }
    }

    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++)  answer.push_back(v[i].idx); 
    
    return answer;
}
