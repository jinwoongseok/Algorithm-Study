#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct info{
    int x;
    int y;
    int idx;
};

class Node{
public:
    Node* left;
    Node* right;
    info data;
    Node(info a){
        left=NULL;
        right=NULL;
        data.x=a.x;
        data.y=a.y;
        data.idx=a.idx;
    }
};

bool comp(info a, info b){
    return a.y>b.y;
}

void insert(Node* root, info d){
    Node* node=new Node(d);
    Node* p=root;
    while(true){
        if(p->data.x<node->data.x){
            if(p->right==NULL){
                p->right=node;
                break;
            }
            else{
                p=p->right;
            }
        }
        else{
            if(p->left==NULL){
                p->left=node;
                break;
            }
            else{
                p=p->left;
            }
        }
    }
}

void Preorder(Node* root, vector<int>& pre){
    if(root==NULL)return;
    pre.push_back(root->data.idx);
    Preorder(root->left,pre);
    Preorder(root->right,pre);
}

void Postorder(Node* root,vector<int>& post){
    if(root==NULL)return;
    Postorder(root->left,post);
    Postorder(root->right,post);
    post.push_back(root->data.idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<info> tmp;
    for(int i=0;i<nodeinfo.size();i++){
        tmp.push_back({nodeinfo[i][0], nodeinfo[i][1], i+1});
    }
    sort(tmp.begin(),tmp.end(),comp);
    Node* root=new Node(tmp[0]);
    for(int i=1;i<tmp.size();i++){
        info data;
        data.x=tmp[i].x;
        data.y=tmp[i].y;
        data.idx=tmp[i].idx;
        insert(root, data);
    }
    vector<int> pre;
    vector<int> post;
    Preorder(root,pre);
    Postorder(root,post);
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}
