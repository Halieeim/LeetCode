/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    TreeNode* root;
    vector<int> v;
    int idx;
    bool flag;
public:
    BSTIterator(TreeNode* root) {
        this->root = root;
        flag = true;
        idx = 0;
    }
    void TreeToVec(TreeNode* root, vector<int>& vec){
        if(!root) return;

        TreeToVec(root->left, vec);
        vec.push_back(root->val);
        TreeToVec(root->right, vec);
    }
    int next() {
        if(flag){
            flag = false;
            TreeToVec(root, v);
            sort(v.begin(), v.end());
        }
        return v[idx++];
    }
    
    bool hasNext() {
        if(flag){
            flag = false;
            TreeToVec(root, v);
            sort(v.begin(), v.end());
        }
        if(idx < v.size()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */