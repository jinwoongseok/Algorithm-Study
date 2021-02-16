#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
bool comp(pii a,pii b)
{
    if(a.second-a.first == b.second-b.first)
        return a.first<b.first;
    return a.second-a.first < b.second-b.first;
}

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set <string> s;
    map <string,int> m;
    for(int i=0;i<gems.size();i++){
        s.insert(gems[i]);
    }
    vector <pii> v;
    int lo=0; int hi=0;

    while(true)
    {
        if(m.size()==s.size())
        {
            if(hi>gems.size()) break;
            v.push_back(make_pair(lo,hi-1));
            //다음 영역 이동 전 가장 마지막 위치에 있는 보석을 map에서 지운다.
            if(m[gems[lo]]==lo)
                m.erase(gems[lo]);
            lo++;
        }
        else
        {
            if(hi>=gems.size()) break;
            m[gems[hi]]=hi;
            hi++;
        }
    }
    sort(v.begin(),v.end(),comp);
    answer.push_back(v[0].first+1);
    answer.push_back(v[0].second+1);
    return answer;
}
