#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100000
using namespace std;

struct discussion {
	long start;
	long end;
};
int n;
vector<discussion> v;
int result;
long maxTime;

bool comp(discussion a, discussion b) {
	if (a.end == b.end) {
		return a.start < b.start;
	}
	else {
		return a.end < b.end;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		long a, b;
		cin >> a >> b;
		maxTime = max(maxTime, b);
		discussion d;
		d.start = a;
		d.end = b;
		v.push_back(d);
	}
	sort(v.begin(), v.end(), comp);
	int tmpStart= 0;
	int tmpEnd = 0;
	for (int i = 0; i < v.size(); i++) {
		int start = v[i].start;
		if (start >= tmpEnd) {
			result++;
			tmpEnd = v[i].end;
		}
	}
	cout << result;
	return 0;
}