#include <iostream>
#include <string>
#include <stack>
using namespace std;

string answer,input;
stack<char> save;

int main() {
	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] >= 'A' && input[i] <= 'Z') {// 1. 알파벳인 경우 
			answer += input[i];
		} 		
		else { // 2. 연산자인 경우
			if (input[i] == '+' || input[i] == '-') { // + - 인 경우
				while (!save.empty() && save.top() != '(') { // 스택이 비거나 ( 를 만날때 까지 
					answer += save.top();
					save.pop();
				}
				save.push(input[i]);
			}
			else if (input[i] == '*' || input[i] == '/') { // * / 인 경우
				while (!save.empty() && (save.top() == '*' || save.top() == '/')) { // 스택이 비거나 스택 top이 +나 -일때까지 
					answer += save.top();
					save.pop();
				}
				save.push(input[i]);
			}
			else if (input[i] == '(') {
				save.push(input[i]);
			}
			else if (input[i] == ')') {
				while (!save.empty() && save.top() != '(') {
					answer += save.top();
					save.pop();
				}
				save.pop();
			}
		}
	}
	while (!save.empty()) {
		answer += save.top();
		save.pop();
	}
	cout << answer;
	return 0;
}

/*
중위표기식 -> 후위표기식
1. 알파벳인 경우, answer에 추가
2. 연산자일 경우
    2-1. +,- 인 경우 우선순위가 가장 낮으므로 스택이 비거나 (를 만날 때까지 answer에 추가후 pop
    2-2. *,/ 인 경우 우선순위가 가장 높으므로 스택이 비거나 +,-가 나올 때 까지 answer에 추가
    2-3 (인 경우 우선순위가 가장 높으므로 스택에 바로 입력
    2-4 )인 경우 (가 나올 때 까지 answer에 추가하고 pop연산을 한다. 
3. 스택에 남아있는 연산자가 있는 경우 answer에 전부 추가
*/