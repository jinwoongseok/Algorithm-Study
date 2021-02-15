#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> save; // 모든 보석들의 처음 개수
map<string, int> m;
map<string, bool> check;
vector < pair<int, pair<int, int>>> sol;
int Min = 987654321;
int dist;
int gem; // 중복되지 않은 보석의 개수

vector<int> solution(vector<string> gems) {
	vector<int> answer;

	for (int i = 0; i < gems.size(); i++) {
		string tmp = gems[i];
		if (m[tmp] == 0) {
			gem++;
		}
		save[tmp]++;
		m[tmp]++;
	}

  /* 투포인터를 사용하기 위한 변수*/
	int left = 0; int right = 0;
	string cmp; // 현재 위치에서 보석.

  /* 보석 종류가 1개가 아닐때 */
  if(gem!=1){
    while (true) {
      if (gem != 0 && right == gems.size()) break;

      /* 보석의 모든 종류를 가지고 있을 때 */
      if (gem==0) {

        /* 거리가 가장 작은 것 중에서 제일 처음 나온 위치 저장*/
        if (dist < Min) {
          Min = dist;
          sol.push_back(make_pair(Min, make_pair(left+1, right)));
        }
        cmp = gems[left++];
        dist--;
        m[cmp]++;

        /* 보석을 장바구니에서 모두 꺼낸 경우*/
        if (m[cmp] == save[cmp]) {
          gem++;
          check[cmp] = false;
        }

      }
      /* 보석의 모든 종류를 가지고 있지 않을 때 */
      else {
        cmp = gems[right++];

        /* 장바구니에 해당 보석이 없을 때*/
        if (check[cmp] == false) {
          check[cmp] = true;
          gem--;
        }
        dist++;
        m[cmp]--;
      }


    }
    sort(sol.begin(),sol.end());
    answer.push_back(sol[0].second.first);
    answer.push_back(sol[0].second.second);
  }
  /* 1개이면 1,1 출력 */
  else {
      answer.push_back(1);
      answer.push_back(1);
  }

	return answer;
}
