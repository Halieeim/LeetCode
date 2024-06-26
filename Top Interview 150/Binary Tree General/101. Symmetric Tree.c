/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool check(struct TreeNode* root1, struct TreeNode* root2){
    if(!root1 && !root2) return true;
    else if(!root1 || !root2) return false;
    else if(root1->val != root2->val) return false;

    return check(root1->right, root2->left) && check(root1->left, root2->right);
}
bool isSymmetric(struct TreeNode* root) {
   if(!root) return true;
   return check(root->left, root->right);
}