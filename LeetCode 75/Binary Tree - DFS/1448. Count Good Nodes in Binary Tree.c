/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
void isGood(struct TreeNode* root, int max, int* counter){
    if(root == NULL) return;
    if(root->val >= max) {
        (*counter)++;
        max = root->val;
    }

    isGood(root->left, max, counter);
    //max = 0;
    isGood(root->right, max, counter);
}

int goodNodes(struct TreeNode* root){
    int counter = 0;
    isGood(root, INT_MIN, &counter);
    return counter;
}