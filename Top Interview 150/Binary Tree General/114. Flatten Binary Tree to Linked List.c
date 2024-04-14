/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void f(struct TreeNode* root, struct TreeNode** prev){
    if(!root) return;    
    f(root->right, prev);
    f(root->left, prev);

    root->right = *prev;
    root->left = NULL;
    *prev = root;
}

void flatten(struct TreeNode* root) {
    struct TreeNode* prev = NULL;
    f(root, &prev);
}