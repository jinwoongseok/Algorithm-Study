#include <queue>
#include <vector>
#include <string>
using namespace std;

vector<pair<int, int>> L(1);
vector<pair<int, int>> R(1);
vector<vector<bool>> check;
int phone[4][3];

/*
	눌러야하는 숫자가 2,5,8,0일때 거리 측정
*/
int bfs(vector<pair<int,int>> cmp,int ref) {
	int x = 0;
	int y = 0;

	check.assign(4, vector<bool>(3, false));
	queue<pair<int, pair<int,int>>> q;

	x = cmp[0].first; y = cmp[0].second;
	q.push(make_pair(0, make_pair(x, y)));
	check[x][y] = true;

	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { 1,-1,0,0 };

	while (!q.empty()) {
		int cnt = q.front().first;
		int cx = q.front().second.first;
		int cy = q.front().second.second;
		q.pop();

		if (phone[cx][cy] == ref) return cnt;


		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 0 && ny >= 0 && nx < 4 && ny < 3&&check[nx][ny]==false) {
				check[nx][ny] = true;
				q.push(make_pair(cnt+1,make_pair(nx, ny)));
			}
		}
	}

}
string solution(vector<int> numbers, string hand) {
	string answer = "";

	/* 키패드 초기화 */
	int num = 1;
	for(int i=0;i<3;i++){
		for (int j = 0; j < 3; j++) {
			phone[i][j] = num;
			num++;
		}
	}
	phone[3][1] = 0;
	phone[3][0] = phone[3][2] = -1;

	/* 왼손은 *, 오른손은 # */
	L[0].first = 3; L[0].second = 0;
	R[0].first = 3; R[0].second = 2;


	for (int i = 0; i < numbers.size(); i++) {
		int tmp = numbers[i];

		/* 1,4,7 일떈 왼손 */
		if (tmp == 1 || tmp == 4 || tmp == 7) {
			L[0].first = (tmp / 3);
			L[0].second = 0;
			answer += 'L';
		}
		/* 3,6,9 일떈 오른손 */
		if(tmp == 3 || tmp == 6 || tmp == 9){
			R[0].first = (tmp/3)-1;
			R[0].second = 2;
			answer += 'R';
		}
		/* 2,5,8,0 일땐 거리 측정 */
		if(tmp == 2 || tmp == 5 || tmp == 8 || tmp==0){
			int Left = bfs(L, tmp);
			int Right = bfs(R, tmp);

			if (Left > Right) {
				if (tmp == 0) R[0].first = 3;
				else R[0].first = (tmp / 3);
				R[0].second = 1;
				answer += 'R';
			}
			else if (Left < Right) {
				if (tmp == 0) L[0].first = 3;
				else L[0].first = (tmp / 3);
				L[0].second = 1;
				answer += 'L';
			}
			/* 거리가 같은 경우 hand 값에 따라 결정. */
			else {
				if (hand == "right") {
					if (tmp == 0) R[0].first = 3;
					else R[0].first = (tmp / 3);
					R[0].second = 1;
					answer += 'R';
				}
				else {
					if (tmp == 0) L[0].first = 3;
					else L[0].first = (tmp / 3);
					L[0].second = 1;
					answer += 'L';
				}
			}
		}


	}
	return answer;
}
