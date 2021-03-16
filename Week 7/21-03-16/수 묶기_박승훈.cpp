#include <iostream>
#include <queue>
using namespace std;
int n;
priority_queue<int> p; 
priority_queue<int> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int answer = 0;
	int cnt = 0;
	int tmp = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (x <= 0) { // x<=0 일땐 minus 수열
			m.push(-x);
		}
		else if (x > 1) p.push(x); // x>1일땐 plus 수열
		else answer += 1; // x=1일땐 answer+=1
	}

	while (!m.empty()) {
		if (cnt == 0) { // 첫번째 수
			tmp = -m.top();
			if (m.size() == 1) answer += tmp; // 마지막 하나 남았을 때
			m.pop();
			cnt++;
		}
		else { // 두번째 수
			tmp *= -m.top(); // 두 수를 곱하기
			m.pop();
			answer += tmp;	
			tmp = 0;
			cnt--;
		}
	}
	cnt = 0;
	tmp = 0;
	while (!p.empty()) {
		if (cnt == 0) { // 첫번째 수
			tmp = p.top();
			if (p.size() == 1) answer += tmp; // 마지막 하나 남았을 때
			p.pop();
			cnt++;
		}
		else { // 두번째 수
			tmp *= p.top(); // 두 수를 곱하기
			p.pop();
			answer += tmp;
			tmp = 0;
			cnt--;
		}
	}
	cout << answer;
}
/*
우선 순위큐는 내림차순 정렬 
*/