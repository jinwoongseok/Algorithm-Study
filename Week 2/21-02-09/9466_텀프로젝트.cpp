/*
	백준 9466번 텀 프로젝트

	풀이:
		1. 현재 방문 중인 배열 = now[num], 방문 여부 = visit[num]
		2. now[num]에 기록된 배열을 다시 방문한다면, 그 edge는 backedge이다. (사이클 존재)
		3. 따라서 cycle[num]=1로 해당 정점에서 cycle 여부를 기록한다.
		4. next!=num일때는 시작한 cycle로 되돌아 오지 않은 경우
*/

#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int T,n;
vector<int> student;
vector<int> visit;
vector<int> cycle;
vector<int> now;

int dfs(int num) {
	if (now[num]) return num;
	if (visit[num]) return 0;

	now[num] = 1; visit[num] = 1;
	int next = dfs(student[num]);
	now[num] = 0;

	if (next > 0) {
		cycle[num] = 1;
		if (next != num) return next;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int test = 0; test < T; test++) {
		cin >> n;
		student.assign(n + 1,0);
		visit.assign(n + 1, 0);
		cycle.assign(n + 1, 0);
		now.assign(n + 1, 0);

		for (int i = 1; i <= n; i++) cin >> student[i];

		for (int i = 1; i <= n; i++) {
			if(cycle[i]==0) dfs(i);
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (cycle[i] == 0) cnt++;
		}

		cout << cnt << '\n';
	}
}

/*
	ex)
	(1) num=4이면
		now[4]=visit[4]=0이므로 now[4]=visit[4]=1
		next=dfs(7)=4 (2)의 결과
		now[4]=0

		next>0이므로 cycle[4]=1이고 return 0(next==num)

	(2) num=7이면
		now[7]=visit[7]=0이므로 now[7]=visit[7]=1
		next=dfs(6)=4 (3)의 결과
		now[7]=0

		next>0이므로 cycle[7]=1이고 return 4


	(3) num=6이면
		now[6]=visit[6]=0이므로 now[6]=visit[6]=1
		next=dfs(4)=4 (4)의 결과
		now[6]=0

		next>0이므로 cycle[6]=1이고 return 4

	(4) num=4이면
		now[4]=1이므로 return 4 (backedge)
*/
