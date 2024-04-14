/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void getLeaves(struct TreeNode* root, int* data, int* idx){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) data[(*idx)++] = root->val;

    getLeaves(root->left, data, idx);
    getLeaves(root->right, data, idx);    
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    if(root1 == NULL && root2 == NULL) return true;
    else if(root1 == NULL || root2 == NULL) return false;

    int* data1 = (int*)malloc(200 * sizeof(int));
    int idx1 = 0, idx2 = 0;
    int* data2 = (int*)malloc(200 * sizeof(int));
    getLeaves(root1, data1, &idx1);
    getLeaves(root2, data2, &idx2);
    // check similarity
    if(idx1 != idx2) return false;
    for(int i = 0; i < idx1 ; i++){
        if(data1[i] != data2[i]) return false;
    }
    
    return true;
}