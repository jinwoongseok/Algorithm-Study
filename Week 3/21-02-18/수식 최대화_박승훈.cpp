#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<long long> num;
vector<char> op;

bool check[3];
bool op_check[3];
vector<int> op_cnt;
int op_priorty[3];
long long ans;

/* 계산 알고리즘 */
long long cal() {
	vector<long long> num_copy=num;
	vector<char> op_copy=op;
	vector<long long> num_tmp;
	vector<char> op_tmp;

	long long z;
	for (int i = 0; i < op_cnt.size(); i++) {
		int size = op_copy.size();
		z = 0;

		for (int j = 0; j < size; j++) {
			// 우선 순위에 맞는 연산자가 나올 땐 계산
			if (op_priorty[i] == 0 && op_copy[j] == '+') {
				z = num_copy[j] + num_copy[j + 1];
				num_copy[j + 1] = z;
			}
			else if (op_priorty[i] == 1 && op_copy[j] == '-') {
				z = num_copy[j] - num_copy[j + 1];
				num_copy[j + 1] = z;
			}
			else if (op_priorty[i] == 2 && op_copy[j] == '*') {
				z = num_copy[j] * num_copy[j + 1];
				num_copy[j + 1] = z;
			}
			// 우선 순위에 맞지 않는 연산자가 나올 땐 다음 연산자로
			else {
				num_tmp.push_back(num_copy[j]);
				op_tmp.push_back(op_copy[j]);
			}
		}
		num_tmp.push_back(num_copy[size]);
		num_copy = num_tmp; op_copy = op_tmp;
		num_tmp.clear(); op_tmp.clear();
	}
	// 스택으로 생각하면 편한 계산기

	return abs(num_copy[0]);
}

/* 연산자의 우선순위 결정 알고리즘 - 백트래킹 */
void priori(int cnt) {

	if (cnt == op_cnt.size()) {

		long long result = cal();
		if (ans < result) {
			ans = result;
			return;
		}
	}

	for (int i = 0; i < op_cnt.size();i++) {
		if (check[op_cnt[i]]==false) {
			check[op_cnt[i]] = true;
			op_priorty[cnt] = op_cnt[i];
			priori(cnt + 1);
			check[op_cnt[i]] = false;
		}
	}
	return ;


}
long long solution(string expression) {

	long long answer=0;

	// 연산자의 개수 및 종류
	string num_s = "";
	long long num_n = 0;

for (int i = 0; i < expression.size(); i++) {

		if(expression[i]>='0'&&expression[i]<='9') {
			num_s += expression[i];
		}
		else{
				num_n = stoll(num_s);
				num_s.clear();

				if (expression[i] == '+' ){
					op.push_back('+');
					if(op_check[0] == false) { op_check[0] = true; op_cnt.push_back(0); }
				}
				else if (expression[i] == '-' ) {
					op.push_back('-');
					if (op_check[1] == false) { op_check[1] = true; op_cnt.push_back(1);}
				}
				else if (expression[i] == '*' ) {
					op.push_back('*');
					if (op_check[2] == false) { op_check[2] = true; op_cnt.push_back(2);}
				}
				num.push_back(num_n);
		}
}
	num_n = stoll(num_s);
	num.push_back(num_n);
	num_s.clear();


	priori(0);
	answer = ans;
	return answer;

}
