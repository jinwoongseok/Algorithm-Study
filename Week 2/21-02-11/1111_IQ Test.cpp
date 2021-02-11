
/*
	백준 1111번 IQ Test

	모든 답을 구하는 규칙 = 앞 수 * a + b  (a,b는 정수이다.)
	규칙에 맞게 다음 수를 구하는 프로그램을 작성하라.

	1. 숫자가 1개일 때는 다음에 나올 수가 여러개.
	2.  숫자가 2개일 때는
		2-1. 2개의 숫자가 같으면 다음에 나올수 있는 숫자는 1개 뿐
		2-2. 2개의 숫자가 다르면 다음에 나올 수는 무수히 많다.
	3. 숫자가 2개 이상일 때는
		3-1. num[0] == num[1] 일때 a=0, b=num[1]이다.
		3-2. num[0] != num[1] 일때 a=(num[2] - num[1]) / (num[1] - num[0]), b = num[1] - num[0] * a 이다.

	다음 수가 여러개 A
			  없을 때 B
			  1개일 때 다음 수
*/

#include <iostream>
using namespace std;

int n,cnt;
int num[50];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];
	int a = 0;
	int b = 0;

	if (n > 2) {
		if (num[0] == num[1]) {
			a = 0; b = num[1];
		}
		else {
			a = (num[2] - num[1]) / (num[1] - num[0]);
			b = num[1] - num[0] * a;
		}
		bool flag = false;
		for (int i = 1; i < n; i++) {
			if ((num[i - 1] * a + b) != num[i]) {
				flag = true;
				break;
			}
		}

		if (flag) cout << "B\n";
		else cout << num[n - 1] * a + b;

	}
	else if (n == 1) {
		cout << "A\n";
	}
	else if (n == 2) {
		if (num[0] == num[1]) cout << num[0] << '\n';
		else cout << "A\n";
	}


	return 0;
}
