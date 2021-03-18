#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#define endl "\n"
using namespace std;

int n;
vector<string> v;
int alphabet[26];

bool comp(int a, int b) {
	return a > b;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	//계수 저장
	for (int i = 0; i < n; i++) {
		int len = v[i].size();
		for (int j = 0; j < len; j++) {
			alphabet[v[i][j] - 'A'] += pow(10, len - j - 1);
		}
	}
	sort(alphabet, alphabet + 26, comp);
	int sum = 0;
	int val = 9;
	for (int i = 0; i < 26; i++) {
		sum += alphabet[i] * val;
		val--;
	}
	cout << sum;
	return 0;
}