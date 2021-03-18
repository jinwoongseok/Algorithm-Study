#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<pair<int, char>> num;
int alpha[26];

bool cmp(int a, int b) {
	if (a > b) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int Pow = 1;

		for (int j = s.length() - 1; j >= 0; j--) { // 알파벳의 자리수 만큼 입력
			alpha[s[j] - 'A'] += Pow;
			Pow *= 10;
		}
	}
	sort(alpha, alpha + 26, cmp); // 알파벳의 자리수가 큰 순서대로 정렬


	int ref = 9;
	int tot = 0;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] == 0) break; // 문자열에 포함되지 않은 경우엔 break;
		tot += (alpha[i] * ref);
		ref--;
	}
	cout << tot << '\n';

}
/*
	ex)  
	ABBA
	CAAB
	alpha[0]=1111, alpha[1]=111, alpha[2]=1000 
*/
