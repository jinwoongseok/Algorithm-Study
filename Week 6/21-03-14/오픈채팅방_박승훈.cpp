#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<pair<string,int>> v; // id와 상태 저장
	map<string, string> m; // id와 닉네임 저장

	for (int test = 0; test < record.size(); test++) {
		string text = record[test];
		string id = "";
		string name = "";
		int cnt = 0;

		for (int i = 0; i < text.size(); i++) {
			
			if (cnt == 1 && text[i] != ' ') id += text[i];
			if (cnt == 2 && text[i] != ' ') name += text[i];
			if (text[i] == ' ') cnt++;

		} // 문자열 나누기 

		if (text[0] == 'E') { // 입장
		  v.push_back(make_pair(id, 0)); 
			m[id] = name;
		}
		else if (text[0] == 'L') { // 퇴장
			v.push_back(make_pair(id, 1));
		}
		else if (text[0] == 'C') { // 닉네임 변경
			m[id] = name;
		}
	}
	
  string input = "";
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second == 0) { // 입장할 때
		
			input += m[v[i].first]; // 해당 id의 닉네임 
			input += "님이 들어왔습니다.";

			answer.push_back(input);
		}
		else { // 퇴장 할 때
			input += m[v[i].first]; // 해당 id의 닉네임
			input += "님이 나갔습니다.";

			answer.push_back(input);
		}
    input.clear();
	}

	return answer;
}
