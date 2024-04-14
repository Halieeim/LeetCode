/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void swap(struct TreeNode* a){
    if(a){
        struct TreeNode* temp = a->left;
        a->left = a->right;
        a->right = temp;
    }
}

struct TreeNode* invertTree(struct TreeNode* root) {
    if(root == NULL) return root;
    swap(root);
    if(root->left) root->left = invertTree(root->left);
    if(root->right) root->right = invertTree(root->right);
    return root;
}