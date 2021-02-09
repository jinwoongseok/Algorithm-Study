/*
	백준 1963번 소수 경로
	https://www.acmicpc.net/problem/1963

	풀이:
	1. 에라토스테네스의 체를 이용해서 1000~9999사이의 모든 소수를 구한다.(prime[num]=false)
	2. 문제의 조건: 시작 숫자부터 `한자리씩 바꾼 것`이 `소수`여야 하므로
		2-1. 한자리 숫자씩 0~9로 바꿔준다.
		2-2. 이때 바꾼 숫자는 소수여야하고, 방문한적이 없어야한다.
			(prime[next]==false && visit[next]==false)
		2-3. 또한 해당 숫자는 1000~999 사이에 존재해야한다.
			(next >= 1000 && next <= 9999)
		2-4. 위 조건을 만족하는 숫자를 queue에 넣고 반복한다.( 원하는 답이 나올때 까지)

*/

#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

vector<bool> prime;
vector<bool> visit;
int A, B;

void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(A, 0));
	visit[A] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == B) {
			cout << cnt << '\n';
			return;
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 10; j++) {
				string num = to_string(cur);
				num[i] = (j + '0');
				int next = stoi(num);

				if (prime[next] == false && visit[next] == false) {
					if (next >= 1000 && next <= 9999) {
						visit[next] = true;
						q.push(make_pair(next, cnt + 1));
					}
				}
			}
		}
	}
	cout << "Impossible\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	prime.resize(10000);
	prime[0] = prime[1] = true;
	for (int i = 2; i <= 9999; i++) {
		if (prime[i] == false) {
			for (int j = i * i; j <= 9999; j += i) prime[j] = true;
		}
	}


	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		visit.assign(10000, false);
		cin >> A >> B;
		bfs();

	}
}
