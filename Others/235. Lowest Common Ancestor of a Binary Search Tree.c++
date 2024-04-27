/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool contains(TreeNode* root, TreeNode* node){
        if(!root) return false;
        if(root == node) return true;

        return contains(root->left, node) || contains(root->right, node);
    }
    void getLCA(TreeNode* root, TreeNode*& LCA, TreeNode* p, TreeNode* q){
        if(!root) return;
        if(contains(root, p) && contains(root, q)){
            LCA = root;
        }
        else return;
        getLCA(root->left, LCA, p, q);
        getLCA(root->right, LCA, p, q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* LCA;
        getLCA(root, LCA, p, q);
        return LCA;
    }
};