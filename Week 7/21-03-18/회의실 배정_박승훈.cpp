#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Time {
	long long start;
	long long end;
};
int n;
long long x, y;
vector<Time> v;

bool cmp(Time a,Time b) {
	if (a.end == b.end) return a.start < b.start;
	return a.end < b.end;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end(), cmp);

	int cnt = 1;
	long long endTime = v[0].end;
	
	if (n != 1) {
		for (int i = 1; i < n; i++) {
			if (endTime <= v[i].start) {
				endTime = v[i].end;
				cnt++;
			}
		}
	}
	
	cout << cnt << '\n';
	return 0;
}

/*
1. 회의가 끝나는 시간이 가장 빠른 순으로 정렬
2. 나머지 시간표를 확인하여 회의가 끝나는 시간이 시작시간보다 작거나 같을 경우 갱신후 cnt++
*/
