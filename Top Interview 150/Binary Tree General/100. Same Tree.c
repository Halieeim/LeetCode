/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p == NULL && q == NULL) return true;
    if((p != q) && (p == NULL || q == NULL)) return false;
    if(p->val != q->val) return false;
    // else return true;
    bool b1 = isSameTree(p->left, q->left);
    bool b2 = isSameTree(p->right, q->right);
    return (b1 == true) && (b2 == true) ? true : false;
}