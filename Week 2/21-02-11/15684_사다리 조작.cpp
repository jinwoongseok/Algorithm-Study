
/*
	백준 15684번 사다리 조작
	https://www.acmicpc.net/problem/15684

	조건1. 인접한 세로선에 가로선을 놓는다. (한 줄에 여러개 가능)
	조건2. 새로 놓은 가로선의 총 개수가 3개 이상이면 -1, 아니면 최소 개수

	효율성을 위해 백트래킹.

*/

#include <iostream>
using namespace std;

int N, M, H;
int line[32][11];
int ans = 987654321;

// 각자의 자리로 돌아갈 수 있는지 여부
bool check() {

	for (int start = 1; start <= N; start++) {
		int node = start; // 체크할 세로선
		for (int height = 1; height <= H; height++) {
			if (node == 1) {
				if (line[height][node] == 1) {
					node++;
					continue;
				}
				else {
					continue;
				}
			}
			else if (node == N) {
				if (line[height][node-1] == 1) {
					node--;
					continue;
				}
				else {
					continue;
				}
			}
			else {
				if (line[height][node] == 1) {
					node++;
					continue;
				}
				else if(line[height][node-1] == 1){
					node--;
					continue;
				}
				else {
					continue;
				}
			}
		}
		if (node != start) return false; // 세로선이 같은 세로선에 도착하지 않을 경우.
	}
	return true;
}


void sol(int h,int cnt) {

	if (cnt >= 4) return; // 조건. 놓아야할 사다리의 개수가 3개 이상이면 -1 출력
	if (check()) {
		ans = min(ans, cnt);
		return;
	}

	for (int height = h; height <= H; height++) {
		for (int i = 1; i < N; i++) {

			if (line[height][i] == 1) continue;//오른쪽에 사다리를 둔 경우
			if (line[height][i - 1] == 1) continue; //왼쪽에 사다리를 둔 경우

			line[height][i] = 1;
			sol(height, cnt + 1);
			line[height][i] = 0;

		}
	}

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> H;

	if (M == 0) {
		cout << 0 << '\n';
	}
	else {
		// b,b+1 세로선을 a위치에서 연결
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			line[a][b] = 1;
		}
		sol(1,0);
		if (ans == 987654321) cout << -1 << '\n';
		else cout << ans;
	}
	return 0;
}
