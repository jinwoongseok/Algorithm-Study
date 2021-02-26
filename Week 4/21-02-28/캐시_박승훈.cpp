#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> cache;
vector<string>::iterator iter;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    if (cacheSize > 0) {
        for (int i = 0; i < cities.size(); i++) {
            // cities를 전부 소문자로 바꿔주는 연산
            for (int k = 0; k < cities[i].size(); k++) {
                cities[i][k] = tolower(cities[i][k]);
            }

            // find 함수를 이용해 cache에서 cities[i]의 iter를 확인
            iter = find(cache.begin(), cache.end(), cities[i]);

            // erase함수를 사용해 지워준다. ( 해당 위치를 지우고 한칸씩 땡겨오는 함수 )
            if (iter == cache.end()) { // cache miss
                if (cache.size() == cacheSize) cache.erase(cache.begin());
                answer += 5;
            }
            else { // cache hit
                cache.erase(iter);
                answer += 1;
            }
            cache.push_back(cities[i]);
        }
    }
    else answer = cities.size() * 5;

    return answer;
}