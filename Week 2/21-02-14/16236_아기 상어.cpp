/*
	N*N 크기의 공간에 물고기 M마리와 아기상어 1마리 존재.(상어는 1초에 상하좌우로 1칸씩 이동)
	조건 1. 아기상어의 크기 < 물고기 크기를 제외한 모든 곳을 이동 가능.
			아기상어의 크기 > 물고기 크기 만 먹는다.
			크기가 같을경우 지나갈 수 있다.

	조건 2. 먹을수 있는 물고기가 1마리면 그 물고기를 먹는다.
			1마리보다 많을 경우 거리가 가장 가까운 물고기를 먹는다.
				거리는 지나갸아하는 칸의 개수
				거리가 가까운 물고기가 많다면 가장 위, 그러한 물고기가 많다면 가장 왼쪽을 먼저 먹는다.

	조건 3. 자신의 크기와 같은 수의 물고기를 먹으면 크기가 커진다.



*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int box[20][20];
int check[20][20];
// 거리가 가까운 물고기 여러마리일때 가장위
// 가장 위에 거리가 가까운 물고기가 여러마리 일때 왼쪽

int n, sx, sy, eat;

bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}


int bfs(int x, int y, int size) {
	queue<pair<int, int > > q;
	q.push(make_pair(x, y));

	int xx[4] = { 0,0,1,-1 };
	int yy[4] = { 1,-1,0,0 };

	vector<pair<int, int> > ans;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + xx[i];
			int ny = cy + yy[i];


			if (nx >= 0 && ny >= 0 && nx < n && ny < n && check[nx][ny] == 0 && box[nx][ny] <= size) {
				if (box[nx][ny] < size && box[nx][ny] != 0) { // 먹을 수 있는 물고기는  ans에 넣어준다.
					ans.push_back(make_pair(nx, ny));
				}
				check[nx][ny] = check[cx][cy] + 1; // 거리값을 갱신한다.
				q.push(make_pair(nx, ny));
			}
		}
	}

	if (!ans.empty()) { // 먹을수 있는 물고기가 존재하면.
		sort(ans.begin(), ans.end(), cmp); // 같은 거리 중 위쪽, 왼쪽에 있는 것을 우선시 하기 위해 정렬..
		int min = 1000;

		int rx = 0; int ry = 0;

		for (int i = 0; i < ans.size(); i++) {
			int ax = ans[i].first;
			int ay = ans[i].second;

			if (check[ax][ay] < min) { // 거리 값이 최소 일 때,
				min = check[ax][ay]; // 걸리는 시간 (한칸마다 1초)
				rx = ax;
				ry = ay;
			}
		}

		box[sx][sy] = 0; box[rx][ry] = 0; // 먹은 물고기는 치운다.
		sx = rx; sy = ry;

		eat++; // 물고기 먹은 개수 증가
		return min;

	}
	else {
		return 0;
	}
}

int main() {
	cin >> n;

	//공간 값 입력

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> box[i][j];
			if (box[i][j] == 9) { // 아기 상어의 위치
				sx = i;
				sy = j;
			}
		}
	}

	int s = 2; // 아기 상어의 크기
	int answer = 0;
	while (true) {
		int t = bfs(sx, sy, s); //

		if (eat == s) {
			s++;
			eat = 0;
		}

		if (t == 0) {
			cout << answer << '\n';
			break;
		}
		else {
			answer += t;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				check[i][j] = 0;
			}
		}

	}

	return 0;
}
/*
	백준 16236번 아기 상어
*/
