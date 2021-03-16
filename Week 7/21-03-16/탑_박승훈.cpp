#include <iostream>
#include <stack>
using namespace std;

struct top_info{
	int idx;
	int height;
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); // 없으면 시간초과가 뜬다.

	stack<top_info> l;
	int n, top_height;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> top_height;

		while (!l.empty()) {
			if (top_height < l.top().height) { // 입력된 탑의 높이가 스택에 저장된 탑의 높이보다 작을 때 (레이저 수신)
				cout << l.top().idx << ' ';
				break;
			}
			l.pop(); // 입력된 탑의 높이가 스택에 저장된 탑의 높이보다 클 때 (레이저 수신x)
		}
		if (l.empty()) cout << 0 << ' '; // 수신된 레이저가 없는 경우
		l.push({ i + 1,top_height }); // 탑의 정보를 입력
	}
	return 0;
}