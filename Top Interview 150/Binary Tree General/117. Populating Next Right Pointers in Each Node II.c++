/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void getNodesByLevel(Node* root, vector<vector<Node*>>& vec, int idx){
        if(!root) return;
        if(vec.size() <= idx){
            vec.resize(idx + 1);
        }
        vec[idx].push_back(root);
        getNodesByLevel(root->left, vec, idx+1);
        getNodesByLevel(root->right, vec, idx+1);
    }
    Node* connect(Node* root) {
        vector<vector<Node*>> v;
        getNodesByLevel(root, v, 0);
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[i].size()-1; j++){
                v[i][j]->next = v[i][j+1];
            }
        }
        return root;
    }
};