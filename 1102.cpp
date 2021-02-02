#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 16
#define endl "\n"
using namespace std;

int w[MAX][MAX];
int dp[1 << 16];
int n;
bool onoff[16];
string s;
int p;
const int INF = 987654321;

int setBit(int bit, int pos) {
	return bit | (1 << pos);
}

int bitCheck(int bit, int pos) {
	return bit & (1 << pos);
}

int bit_count(int bit) {
	int cnt = 0;
	while (bit) {
		if (bit & 1)cnt++;
		bit /= 2;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}
	for (int i = 0; i < (1 << n); i++) {
		dp[i] = INF;
	}
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'Y')onoff[i] = 1;
	}
	cin >> p;
	int state = 0;
	for (int i = 0; i < n; i++) {
		if (onoff[i] == 1)state = setBit(state, i);
	}
	dp[state] = 0;
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			int nxt, nxtCost;
			if (bitCheck(i, j))continue;
			nxt = setBit(i, j);
			for (int k = 0; k < n; k++) {
				if (bitCheck(i, k)) {
					nxtCost = dp[i] + w[k][j];
					dp[nxt] = min(dp[nxt], nxtCost);
				}
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < (1 << n); i++) {
		int tmp = bit_count(i);
		if (tmp >= p) {
			ans = min(ans, dp[i]);
		}
	}
	cout << ans;


	return 0;
}