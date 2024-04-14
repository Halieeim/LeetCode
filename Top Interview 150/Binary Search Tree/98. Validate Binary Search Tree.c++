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
class Solution {
public:
    map<int,int> table;
    vector<int> vec;
    TreeNode* validate(TreeNode* root, int val){
        while(root){
            if(val == root->val) return root;
            if(val > root->val) root = root->right;
            else root = root->left;
        }
        return root;
    }
    void treeToVec(TreeNode* root){
        if(!root) return;
        table[root->val] = root->val;
        vec.push_back(root->val);
        treeToVec(root->left);
        treeToVec(root->right);
    }

    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        treeToVec(root);
        if(vec.size() != table.size()) return false;
        for(const auto it: table){
            TreeNode* n = validate(root, it.first);
            if(!n) return false;
        }
        return true;
    }
};