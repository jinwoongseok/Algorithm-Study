#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 501
#define endl "\n"
using namespace std;

int n, m;
vector<int> adj[MAX], rev[MAX];
int result;
bool visited[MAX], visitedRev[MAX];
int cnt, cntRev;


void DFS(int cur) {
	if (visited[cur])return;
	visited[cur] = true;
	cnt++;
	for (int i = 0; i < adj[cur].size(); i++) {
		DFS(adj[cur][i]);
	}
}

void DFS_rev(int cur) {
	if (visitedRev[cur])return;
	visitedRev[cur] = true;
	cntRev++;
	for (int i = 0; i < rev[cur].size(); i++) {
		DFS_rev(rev[cur][i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		rev[b].push_back(a);
	}
	//나보다 큰 수를 셈
	//나보다 작은 수를 셈
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		cnt = 0;
		DFS(i);
		memset(visitedRev, 0, sizeof(visitedRev));
		cntRev = 0;
		DFS_rev(i);
		//i번째 학생의 순서를 알 수 있는지 없는지 판단
		if (cnt + cntRev - 1 == n) {
			result++;
		}
	}
	cout << result;
	return 0;
}