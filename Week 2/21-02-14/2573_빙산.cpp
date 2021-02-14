/*
	조건: 빙산의 높이는 바닷물에 많이 접해있는 부분에서 빨리 줄어든다.
		- 동서남북에서 0의 개수만큼 줄어든다. (0보다 작게 줄어들진 않는다.)

	구해야하는 답: 주어진 빙산이 두 덩어리 이상으로 분리되는 최초의 시간을 구한다.

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ice[300][300]; // 빙산 정보
int save[300][300]; // 해당 빙산에서 바닷물의 정보
bool visited[300][300];

int xx[4] = { 0,0,1,-1 };
int yy[4] = { 1,-1,0,0 };
int n, m, check, year;

// 빙산 주변에 바닷물만큼 빙산을 빼주기 위해 바닷물의 개수를 체크한다.
void dfs(int x, int y) {
	visited[x][y] = true;
	int nx = 0;
	int ny = 0;

	for (int i = 0; i < 4; i++) {
		nx = xx[i] + x;
		ny = yy[i] + y;

		if (nx >= 0 && ny >= 0 && nx < n && ny < m && visited[nx][ny] == false) {
			if (ice[nx][ny] == 0) {
				save[x][y]++;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		nx = xx[i] + x;
		ny = yy[i] + y;

		if (nx >= 0 && ny >= 0 && nx < n && ny < m && visited[nx][ny] == false && ice[nx][ny] != 0) {
			dfs(nx, ny);
		}
	}
}

int main() {

	cin >> n >> m;

	// 빙산 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ice[i][j];
		}
	}

	while (true) {
		check = 0;

		// 빙산이 있는 모든 곳에서 체크한다.
		// check: 빙산의 개수
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (ice[i][j] != 0 && visited[i][j] == false) {
					dfs(i, j);
					check++;
				}
			}
		}

		if (check == 0) { year = 0; break; } // 빙산의 개수가 0일 때(빙산이 다 녹음)
		else if (check >= 2) { break; } // 빙산의 개수가 2이상 일 때
		year++;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				visited[i][j] = false;
				// 빙산을 바닷물의 개수만큼 뺴준다.
				if ((ice[i][j] - save[i][j]) < 0) ice[i][j] = 0; // 빙산은 0보다 작아지지 않는다.
				else {
					ice[i][j] -= save[i][j];
				}

				save[i][j] = 0;
			}
		}
	}
	cout << year;
}
/*
	백준 2573번 빙산
*/
