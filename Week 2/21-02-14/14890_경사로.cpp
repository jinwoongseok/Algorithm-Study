#include <iostream>
#include <algorithm>
using namespace std;

int map1[100][100];
int map2[100][100];
int n, l;

bool MakeRoad(int x, int y, int map[][100]) {
	int val = map[y][x];
	int len = l;
	for (int i = x + 1; i < x + len; i++) {
		if (map[y][i] != val) return false;
	}
	return true;
}

int solution(int map[][100], int y) {
    //왼쪽부터 시작
	int x = 0;
    //지나온 칸 수
	int len = 1;
	while (x < n - 1) {
        //높이가 같은 경우
		if (map[y][x + 1] == map[y][x]) {
			len++;
			x++;
		}
        //오르막 경사로
		else if (map[y][x + 1] - map[y][x] == 1) {
            //만약 지나온 칸 수가 경사로의 길이보다 크거나 같으면 경사로를 두고 초기화
			if (len >= l) {
				x++;
				len = 1;
			}
            //아니면 경사로 둘 수 없다
			else {
				return 0;
			}
		}
        //내리막 경사로
		else if (map[y][x + 1] == map[y][x] - 1) {
            //내리막 경사로 둘 수 있는 경우 경사로를 두고 현재 지나온 칸수는 0이 된다. 현 위치는 경사로의 끝 지점임
			if (MakeRoad(x + 1, y, map)) {
				x += l;
				len = 0;
			}
			else {
				return 0;
			}
		}
        //높이가 2이상 차이나는 경우
		else if (abs(map[y][x + 1] - map[y][x]) > 1) {
			return 0;
		}
	}
	return 1;
}

int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map1[i][j];
            //맵을 뒤바꾼 것을 생성
			map2[j][i] = map1[i][j];
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += solution(map1, i);
		sum += solution(map2, i);
	}
	cout << sum;
	return 0;
}
