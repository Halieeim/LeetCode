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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        TreeNode* tree = (TreeNode*)malloc(sizeof(TreeNode));
        TreeNode* subTree = tree;
        
        if(root->val == val) return root;

        subTree = searchBST(root->left, val);
        if(subTree != tree && subTree != NULL) return subTree; 
        subTree = searchBST(root->right, val);

        return subTree;
    }
};