#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string in,boom;
vector<char> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> in >> boom;

	for (int i = 0; i < in.size(); i++) {
		char word = in[i];
		
		v.push_back(word);
		if (word == boom[boom.size()-1]) {
			if (v.size() < boom.size()) continue;

			int cnt = 0;
			int idx = v.size()-1;
			for (int j = boom.size()-1;j >= 0;j--){
				if (boom[j] == v[idx--]) cnt++;
			}
			if (boom.size() == cnt) {
				for (int j = 0; j < cnt; j++) v.pop_back();
			}
		}
	}
	if (!v.empty()) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
	}
	else cout << "FRULA\n";
	return 0;
}

/*
1. 폭발 문자열의 맨 마지막 문자와 확인할 문자열의 문자가 같은지 확인.
	1-1. 확인할 문자열의 크기가 폭발 문자열보다 큰 경우만 확인
	1-2. 폭발 문자열의 크기만큼 뒤에서 부터확인
	1-3. cnt가 같으면 숫자만큼 v에서 제외
*/
