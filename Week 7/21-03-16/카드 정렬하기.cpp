#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> card;
int n,num;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	if (n == 1) { // 카드 뭉치가 1개일 때 ,  합치는 과정 0번
		cin >> num;
		cout << 0;
		return 0;
	}
	else { // 카드 뭉치가 2개 이상 일때
		for (int i = 0; i < n; i++) {
			cin >> num;
			card.push(-num);
		} // 작은 수부터 우선순위큐

		int answer = 0;
		int cnt = 0;
		int tmp = 0;

		while (!card.empty()) {
			if (cnt == 0) { // 카드 묶음 첫번째
				tmp = -card.top();
				if (card.size() == 1) { // 카드 뭉치가 하나 남았을 때 
					cout << answer << '\n';
					return 0;
				}
				card.pop();
				cnt++;
			}
			else { // 카드 묶음 두번째
				tmp -= card.top();
				card.pop();
				answer += tmp;
				card.push(-tmp);
				cnt--;
			}
			
		}
	}
}