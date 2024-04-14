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
    vector<int> vec;
    void treeToVec(TreeNode* root){
        if(!root) return;

        vec.push_back(root->val);
        treeToVec(root->left);
        treeToVec(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        treeToVec(root);
        sort(vec.begin(), vec.end());
        return vec[k-1];
    }
};