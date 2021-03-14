#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
    int x;
    int y;
    int idx;
    Node* leftN;
    Node* rightN;
};

vector<Node> Tree;
vector<int> Pre;
vector<int> Post;

void pre(Node* node) {
    if (node == NULL) return;
    Pre.push_back(node->idx);
    pre(node->leftN);
    pre(node->rightN);
} // 전위 순회 , 루트 왼쪽 오른쪽

void post(Node* node) {
    if (node == NULL) return;
    post(node->leftN);
    post(node->rightN);
    Post.push_back(node->idx);
} // 후위 순회 , 왼쪽 오른쪽 루트

void insert(Node* parent, Node* child) {
    if (parent-> x < child-> x) { // 조건 1. x 좌표 값이 더 클 때 (오른쪽)
        if (parent->rightN == NULL) parent->rightN = child; // 부모의 자식노드가 정해지지 않으면 해당 노드로 입력
        else insert(parent->rightN, child); // 존재할 때 다음 노드로 이동
    }
    else { // 조건 2. y좌표 값이 더 작을 때 (왼쪽)
        if (parent->leftN == NULL) parent->leftN = child;
        else insert(parent->leftN, child);
    }
}

bool cmp(Node a, Node b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y > b.y;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;

    for (int i = 0; i < nodeinfo.size(); i++) Tree.push_back({ nodeinfo[i][0],nodeinfo[i][1],i + 1 });
    sort(Tree.begin(), Tree.end(), cmp); // 트리 정보 입력 후 정렬
    Node* root = &Tree[0]; // 루트

    for (int i = 1; i < Tree.size(); i++) {
        insert(root, &Tree[i]);
    } // 트리 만들기 
    pre(root);
    post(root);

    answer.push_back(Pre);
    answer.push_back(Post);

    return answer;
}
/*
풀이
1. y값에 대해 정렬 (내림차순)
2. 루트 만들기
    2-1. root 만들기
    2-2. x값을 이용해 루트의 왼쪽 오른쪽 노드 결정.(insert) 
3. 전위 후위 탐색 하기
*/



// y좌표 = 같은 레벨(높이가 높을 수록 트리의 위쪽), 모두 다른 x 좌표
// 자식의 y좌표 < 부모의 y 좌표
// 왼쪽노드 x 값 < 루트 x 값 < 오른쪽노드 x 값
