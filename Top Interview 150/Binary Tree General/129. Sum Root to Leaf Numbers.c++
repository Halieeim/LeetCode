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
    void getPaths(TreeNode* root, vector<int>& vec, unsigned int sum){
        if(!root) return;
        if(!root->left && !root->right){
            sum *= 10;
            sum += root->val;
            vec.push_back(sum);
            return;
        }
        sum *= 10;
        sum += root->val;
        getPaths(root->left, vec, sum);
        getPaths(root->right, vec, sum);
    }

    int sumNumbers(TreeNode* root) {
        vector<int> v;
        int sum = 0;
        getPaths(root, v, sum);
        sum = 0;
        for(int i = 0; i < v.size(); i++){
            sum += v[i];
        }
        return sum;
    }
};